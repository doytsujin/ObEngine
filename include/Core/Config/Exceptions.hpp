#include <Exception.hpp>
#include <string_view>

/**
 * \nobind
 */
namespace obe::config::Exceptions
{
    class InvalidVersionFormat : public Exception<InvalidVersionFormat>
    {
    public:
        using Exception::Exception;
        InvalidVersionFormat(std::string_view detail, DebugInfo info)
            : Exception(info)
        {
            this->error("There is a problem with your version number : {}", detail);
        }
    };

    class ConfigError : public Exception<ConfigError>
    {
    public:
        using Exception::Exception;
        ConfigError(std::vector<std::string> config_files, DebugInfo info)
            : Exception(info)
        {
            this->error("config.vili built from the following files ({}) is malformed",
                fmt::join(config_files, ", "));
        }
    };
} // namespace obe::config::Exceptions
