#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/Api/Input/ISink.h"

namespace PiSubmarine::Control::Api::Input
{
    class ISinkMock : public ISink
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), Submit, (const OperatorCommand& command), (override));
    };
}
