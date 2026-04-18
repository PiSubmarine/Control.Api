#pragma once

#include "PiSubmarine/Control/Api/Input/OperatorCommand.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Control::Api::Input
{
    class ISink
    {
    public:
        virtual ~ISink() = default;

        [[nodiscard]] virtual Error::Api::Result<void> Submit(const OperatorCommand& command) = 0;
    };
}
