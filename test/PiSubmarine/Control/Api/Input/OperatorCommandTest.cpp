#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/OperatorCommand.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(OperatorCommandTest, StoresAllConfiguredInputs)
    {
        const auto movement = Horizontal::Create(
            SignedNormalizedFraction(0.50),
            SignedNormalizedFraction(0.25));

        ASSERT_TRUE(movement.has_value());

        const OperatorCommand command{
            .Movement = movement.value(),
            .VerticalControl = Vertical::SetDepthTargetTo(3.0_m),
            .GimbalTarget = Gimbal::Create(0.5_rad),
            .LampIntensity = Lamp::Create(NormalizedFraction(0.70)),
            .ModeRequest = Mode::Request::HoldPositionValue()};

        EXPECT_EQ(command.Movement, movement.value());
        EXPECT_TRUE(command.VerticalControl.Is<Vertical::SetDepthTarget>());
        ASSERT_TRUE(command.GimbalTarget.has_value());
        EXPECT_EQ(command.GimbalTarget->Pitch(), 0.5_rad);
        ASSERT_TRUE(command.LampIntensity.has_value());
        EXPECT_EQ(command.LampIntensity->Intensity(), NormalizedFraction(0.70));
        ASSERT_TRUE(command.ModeRequest.has_value());
        EXPECT_TRUE(command.ModeRequest->Is<Mode::HoldPosition>());
    }
}
