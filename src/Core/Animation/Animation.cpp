#include <vili/node.hpp>
#include <vili/parser.hpp>
#include <vld8/validator.hpp>

#include <Animation/Animation.hpp>
#include <Animation/AnimationGroup.hpp>
#include <Animation/Exceptions.hpp>
#include <Config/Validators.hpp>
#include <Engine/ResourceManager.hpp>
#include <System/Path.hpp>

namespace obe::animation
{
    AnimationState::AnimationState(const Animation& parent)
        : m_parent(parent)
    {
    }

    void AnimationState::load()
    {
        for (const auto& [group_name, group] : m_parent.m_groups)
        {
            m_groups.emplace(group_name, std::make_unique<AnimationGroup>(*group.get()));
        }
    }

    std::string AnimationState::get_next_animation() const noexcept
    {
        return m_next_animation_name;
    }

    std::string Animation::get_next_animation() const noexcept
    {
        return m_default_state.get_next_animation();
    }

    std::string Animation::get_name() const noexcept
    {
        return m_name;
    }

    time::TimeUnit Animation::get_delay() const noexcept
    {
        return m_delay;
    }

    AnimationGroup& AnimationState::get_animation_group(const std::string& group_name)
    {
        if (const auto group = m_groups.find(group_name); group != m_groups.end())
            return *group->second;
        throw exceptions::UnknownAnimationGroup(
            m_parent.get_name(), group_name, m_parent.get_all_animation_groups_names(), EXC_INFO);
    }

    AnimationGroup& Animation::get_animation_group(const std::string& group_name)
    {
        return m_default_state.get_animation_group(group_name);
    }

    std::string AnimationState::get_current_animation_group() const noexcept
    {
        return m_current_group->get_name();
    }

    std::string Animation::get_current_animation_group() const noexcept
    {
        return m_default_state.get_current_animation_group();
    }

    std::vector<std::string> Animation::get_all_animation_groups_names() const
    {
        std::vector<std::string> group_keys;
        group_keys.reserve(m_groups.size());
        std::transform(m_groups.cbegin(), m_groups.cend(), group_keys.begin(),
            [](const auto& pair) { return pair.first; });
        return group_keys;
    }

    AnimationPlayMode Animation::get_play_mode() const noexcept
    {
        return m_play_mode;
    }

    AnimationStatus AnimationState::get_status() const noexcept
    {
        return m_status;
    }

    AnimationStatus Animation::get_status() const noexcept
    {
        return m_default_state.get_status();
    }

    bool AnimationState::is_over() const noexcept
    {
        return m_over;
    }

    bool Animation::is_over() const noexcept
    {
        return m_default_state.is_over();
    }

    void AnimationState::execute_instruction()
    {
        const vili::node& current_command = m_parent.m_code[m_code_index];
        debug::Log->trace("<animation> Executing instruction {} / {} : {}", m_code_index,
            m_parent.m_code.size() - 1, current_command.dump());
        const AnimationCommand command
            = AnimationCommandMeta::from_string(current_command.at("command").as_string());
        if (command == AnimationCommand::Wait)
        {
            m_feed_instructions = true;
            m_sleep = current_command.at("time");
        }
        else if (command == AnimationCommand::PlayGroup)
        {
            if (m_current_group != nullptr)
                m_current_group->reset();
            m_feed_instructions = false;
            m_current_group = &get_animation_group(current_command.at("group"));
            int repeat = 1;
            if (current_command.contains("repeat"))
            {
                repeat = current_command.at("repeat");
            }
            m_current_group->set_loops(repeat);
        }
        else if (command == AnimationCommand::SetAnimation)
        {
            m_feed_instructions = false;
            m_status = AnimationStatus::Call;
            m_next_animation_name = current_command.at("animation");
        }
        m_code_index++;
        if (m_feed_instructions && m_code_index > m_parent.m_code.size() - 1
            && m_parent.m_play_mode != AnimationPlayMode::OneTime)
        {
            this->reset();
        }
    }

    void AnimationState::update_current_group()
    {
        if (m_current_group == nullptr)
        {
            return;
        }
        debug::Log->trace(
            "    <animation> Updating AnimationGroup '{}'", m_current_group->get_name());
        m_current_group->next();
        if (m_current_group->is_over())
        {
            debug::Log->trace(
                "        <animation> AnimationGroup '{}' is over", m_current_group->get_name());
            if (m_code_index < m_parent.m_code.size())
            {
                debug::Log->trace("    <animation> Restarting code execution");
                m_feed_instructions = true;
                m_current_group->reset();
            }
            else
            {
                debug::Log->trace("    <animation> animation '{}' has no more code to execute");
                if (m_parent.m_play_mode == AnimationPlayMode::OneTime)
                {
                    debug::Log->trace("    <animation> animation '{}' will stay on "
                                      "the last texture");
                    m_current_group->previous(true);
                    m_over = true;
                }
                else
                {
                    debug::Log->trace("    <animation> animation '{}' will reset code execution");
                    m_feed_instructions = true;
                    m_current_group->reset();
                    m_code_index = 0;
                }
            }
        }
    }

    void AnimationState::set_active_animation_group(const std::string& group_name)
    {
        if (m_groups.contains(group_name))
        {
            m_current_group = &get_animation_group(group_name);
        }
        throw exceptions::UnknownAnimationGroup(
            m_parent.m_name, group_name, m_parent.get_all_animation_groups_names(), EXC_INFO);
    }

    void Animation::load_images(const vili::node& images)
    {
        for (auto& image : images)
        {
            std::string texture_name = image;
            debug::Log->trace("    <animation> Loading image '{}'", texture_name);

            std::string path_to_texture = m_path.add(texture_name).to_string();
            debug::Log->trace("    <animation> Found Texture Path at '{}'", path_to_texture);
            if (m_resource_manager)
            {
                debug::Log->trace(
                    "    <animation> Loading Texture {0} (using ResourceManager)", texture_name);
                m_textures.emplace_back(
                    m_resource_manager->get_texture(m_path.add(texture_name), m_anti_aliasing));
            }
            else
            {
                debug::Log->trace("    <animation> Loading Texture {0}", texture_name);
                graphics::Texture new_texture;
                new_texture.load_from_file(m_path.add(texture_name).find(system::PathType::File));
                // TODO: Add a way to configure anti-aliasing for textures without ResourceManager
                m_textures.push_back(std::move(new_texture));
            }
        }
    }

    void Animation::load_groups(const vili::node& groups)
    {
        for (auto [group_name, group] : groups.items())
        {
            debug::Log->trace("    <animation> Loading AnimationGroup '{}'", group_name);
            m_groups.emplace(group_name, std::make_unique<AnimationGroup>(group_name));
            for (vili::node& current_texture : group.at("content"))
            {
                debug::Log->trace("      <animation> Pushing Texture {} into group",
                    current_texture.as<vili::integer>());
                m_groups[group_name]->push_texture(m_textures[current_texture.as<vili::integer>()]);
            }

            if (group.contains("framerate"))
            {
                vili::number delay = group.at("clock");
                debug::Log->trace("      <animation> Setting group delay to {}", delay);
                m_groups[group_name]->set_delay(delay);
            }
            else
            {
                debug::Log->trace(
                    "      <animation> No delay specified, using parent delay : {}", m_delay);
                m_groups[group_name]->set_delay(m_delay);
            }
        }
    }

    void Animation::load_code(const vili::node& code)
    {
        for (const vili::node& command : code)
        {
            debug::Log->trace("    <animation> Parsing animation command '{}'", command);
            m_code.push_back(command);
        }
    }

    Animation::Animation(const system::Path& path, engine::ResourceManager* resources)
        : m_path(path)
        , m_resource_manager(resources)
        , m_default_state(*this)
    {
    }

    void Animation::apply_parameters(vili::node& parameters)
    {
        // TODO: Re-implement texture offset in a better way
        if (parameters.contains("priority"))
            m_priority = parameters.at("priority");
    }

    void AnimationState::update()
    {
        if (!m_over)
        {
            const time::TimeUnit delay = (m_sleep) ? m_sleep : m_parent.m_delay;
            debug::Log->trace("<animation> Delay is {} seconds", delay);
            if (time::epoch() - m_clock > delay)
            {
                m_clock = time::epoch();
                m_sleep = 0;
                debug::Log->trace("<animation> Updating animation '{0}'", m_parent.m_name);

                if (m_feed_instructions)
                {
                    this->execute_instruction();
                }
                this->update_current_group();
            }
        }
    }

    const Animation& AnimationState::get_animation() const
    {
        return m_parent;
    }

    void Animation::set_anti_aliasing(bool anti_aliasing) noexcept
    {
        m_anti_aliasing = anti_aliasing;
    }

    bool Animation::is_anti_aliased() const noexcept
    {
        return m_anti_aliasing;
    }

    AnimationState Animation::make_state() const
    {
        return AnimationState(*this);
    }

    vili::node Animation::schema() const
    {
        return config::validators::animation_validator();
    }

    vili::node Animation::dump() const
    {
        vili::node result = vili::object {};

        result.emplace("Meta", vili::object { { "name", m_name }, { "frameDuration", m_delay } });

        return result;
    }

    void Animation::load(const vili::node& data)
    {
        debug::Log->debug("<animation> Loading animation at {}", m_path.to_string());

        try
        {
            // Meta
            debug::Log->trace("  <animation> Loading Animation base");
            m_name = data.at("name");

            debug::Log->trace("    <animation> animation name = '{}'", m_name);
            if (data.contains("framerate"))
            {
                m_delay = 1.0 / data.at("framerate").as<vili::number>();
                debug::Log->trace("    <animation> animation clock = {}", m_delay);
            }
            if (data.contains("mode"))
            {
                m_play_mode = AnimationPlayModeMeta::from_string(data.at("mode"));
                debug::Log->trace("    <animation> animation play-mode = '{}'",
                    AnimationPlayModeMeta::to_string(m_play_mode));
            }

            // Images
            debug::Log->trace("  <animation> Loading Animation images");
            if (data.contains("images"))
            {
                load_images(data.at("images"));
            }
            else
            {
                debug::Log->warn(
                    "Animation '{}' (located at path '{}') does not contain any images", m_name,
                    m_path.to_string());
            }


            // Groups
            debug::Log->trace("  <animation> Loading Animation groups");
            if (data.contains("groups"))
            {
                load_groups(data.at("groups"));
            }
            else
            {
                debug::Log->warn(
                    "Animation '{}' (located at path '{}') does not contain any groups", m_name,
                    m_path.to_string());
            }

            // animation Code
            debug::Log->trace("  <animation> Loading Animation code");
            if (data.contains("code"))
            {
                load_code(data.at("code"));
            }
            else
            {
                debug::Log->warn("Animation '{}' (located at path '{}') does not contain any code",
                    m_name, m_path.to_string());
            }

            m_default_state.load();
        }
        catch (const std::exception& e)
        {
            throw exceptions::InvalidAnimationFile(m_path.to_string(), EXC_INFO).nest(e);
        }
    }

    void AnimationState::reset() noexcept
    {
        debug::Log->trace("<animation> Resetting animation '{}'", m_parent.m_name);
        for (auto it = m_groups.cbegin(); it != m_groups.cend(); ++it)
            it->second->reset();
        m_status = AnimationStatus::Play;
        m_code_index = 0;
        m_feed_instructions = true;
        m_over = false;
    }

    void Animation::reset() noexcept
    {
        m_default_state.reset();
    }

    void Animation::update()
    {
        m_default_state.update();
    }

    const graphics::Texture& Animation::get_texture_at_index(int index)
    {
        if (index < m_textures.size())
            return m_textures[index];
        throw exceptions::AnimationTextureIndexOverflow(m_name, index, m_textures.size(), EXC_INFO);
    }

    const graphics::Texture& AnimationState::get_texture() const
    {
        if (m_current_group != nullptr)
            return m_current_group->get_current_texture();
        throw exceptions::NoSelectedAnimationGroup(m_parent.m_name, EXC_INFO);
    }

    const graphics::Texture& Animation::get_current_texture() const
    {
        return m_default_state.get_texture();
    }

    int Animation::get_priority() const noexcept
    {
        return m_priority;
    }
} // namespace obe::animation
