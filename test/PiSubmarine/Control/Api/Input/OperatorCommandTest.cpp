#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/OperatorCommand.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(OperatorCommandTest, StoresAllConfiguredInputs)
    {
        const auto movement = Control::Horizontal::Api::Command::Create(
            SignedNormalizedFraction(0.50),
            SignedNormalizedFraction(0.25));

        ASSERT_TRUE(movement.has_value());

        const OperatorCommand command{
            .Movement = movement.value(),
            .VerticalControl = Control::Vertical::Api::Command::SetDepthTargetTo(3.0_m),
            .GimbalTarget = Control::Gimbal::Api::Command::Create(0.5_rad),
            .LampIntensity = Control::Lamp::Api::Command::Create(NormalizedFraction(0.70)),
            .ModeRequest = Mode::Request::HoldPositionValue()};

        EXPECT_EQ(command.Movement, movement.value());
        EXPECT_TRUE(command.VerticalControl.Is<Control::Vertical::Api::Command::SetDepthTarget>());
        ASSERT_TRUE(command.GimbalTarget.has_value());
        EXPECT_EQ(command.GimbalTarget->Pitch(), 0.5_rad);
        ASSERT_TRUE(command.LampIntensity.has_value());
        EXPECT_EQ(command.LampIntensity->Intensity(), NormalizedFraction(0.70));
        ASSERT_TRUE(command.ModeRequest.has_value());
        EXPECT_TRUE(command.ModeRequest->Is<Mode::HoldPosition>());
    }
}
