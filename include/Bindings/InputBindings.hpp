#pragma once

#include <kaguya/kaguya.hpp>

namespace obe
{
    namespace Bindings
    {
        /**
        * \brief Bindings to Input related classes and functions
        */
        namespace InputBindings
        {
            void LoadInputAction(kaguya::State* lua);
            void LoadInputActionEvent(kaguya::State* lua);
            void LoadInputButton(kaguya::State* lua);
            void LoadInputButtonMonitor(kaguya::State* lua);
            void LoadInputCondition(kaguya::State* lua);
            void LoadInputManager(kaguya::State* lua);
            void LoadInputFunctions(kaguya::State* lua);
        }
    }
}