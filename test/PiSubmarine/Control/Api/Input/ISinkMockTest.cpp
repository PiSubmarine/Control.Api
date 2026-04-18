#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/ISinkMock.h"
#include "PiSubmarine/Control/Horizontal/Api/Command.h"
#include "PiSubmarine/Control/Vertical/Api/Command.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(ISinkMockTest, SubmitReturnsConfiguredSuccess)
    {
        ISinkMock sinkMock;
        const auto movement = Horizontal::Api::Command::Create(
            SignedNormalizedFraction(0.40),
            SignedNormalizedFraction(0.20));

        ASSERT_TRUE(movement.has_value());

        const OperatorCommand command{
            .Movement = movement.value(),
            .VerticalControl = Vertical::Api::Command::KeepCurrentValue(),
            .GimbalTarget = std::nullopt,
            .LampIntensity = std::nullopt,
            .ModeRequest = std::nullopt};

        EXPECT_CALL(sinkMock, Submit(command))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        const auto result = sinkMock.Submit(command);

        EXPECT_TRUE(result.has_value());
    }
}
