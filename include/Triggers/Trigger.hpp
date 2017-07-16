#pragma once

#include <kaguya/kaguya.hpp>

#include <Types/Any.hpp>
#include <Utils/StringUtils.hpp>
#include <Utils/VectorUtils.hpp>

namespace obe
{
    namespace Triggers
    {
        class TriggerGroup;
        class Trigger
        {
        private:
            TriggerGroup* m_parent;
            std::string m_name;
            std::map<std::string, std::pair<std::string, Types::Any>> m_triggerParameters;
            bool m_enabled = false;
            bool m_toEnable = false;
            bool m_toDisable = false;
            bool m_permanent = false;
            void clearParameters();
            template <typename P>
            void pushParameter(std::string name, P parameter);
            friend class TriggerGroup;
            friend class TriggerDatabase;
        public:
            /**
             * \brief Creates a new Trigger
             * \param parent Pointer to the parent TriggerGroup
             * \param name Name of the Trigger
             * \param startState State of the Trigger when created (enabled / disabled)
             * \param permanent If equals to true, when the Trigger will be enabled it will stay enabled
             */
            explicit Trigger(TriggerGroup* parent, const std::string& name, bool startState = false, bool permanent = false);
            /**
             * \brief 
             * \return 
             */
            bool getState() const;
            bool isPermanent() const;
            std::string getGroup() const;
            std::string getName() const;
            std::string getNamespace() const;
            std::map<std::string, std::pair<std::string, Types::Any>>* getParameters();
        };

        std::string injectParameters(Trigger& trigger, kaguya::State& lua);

        template <typename P>
        void Trigger::pushParameter(std::string name, P parameter)
        {
            std::vector<std::string> splittedTypeName = Utils::String::split(typeid(parameter).name(), " ");
            std::string datatype = Utils::Vector::join(splittedTypeName, "", 1);
            m_triggerParameters[name] = std::pair<std::string, Types::Any>(datatype, Types::Any(parameter));
        }
    }
}