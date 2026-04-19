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
            .LeaseId = Lease::Api::LeaseId{.Value = "lease-1"},
            .Movement = movement.value(),
            .VerticalControl = Control::Vertical::Api::Command::SetDepthTargetTo(3.0_m),
            .GimbalTarget = Control::Gimbal::Api::Command::Create(0.5_rad),
            .LampIntensity = Control::Lamp::Api::Command::Create(NormalizedFraction(0.70)),
            .VideoControl = Control::Video::Api::Command::Enable(
                Control::Video::Api::StreamProfile::Standard,
                Control::Video::Api::AutoFocus{}),
            .ModeRequest = Mode::Request::HoldPositionValue()};

        EXPECT_EQ(command.LeaseId.Value, "lease-1");
        EXPECT_EQ(command.Movement, movement.value());
        EXPECT_TRUE(command.VerticalControl.Is<Control::Vertical::Api::Command::SetDepthTarget>());
        ASSERT_TRUE(command.GimbalTarget.has_value());
        EXPECT_EQ(command.GimbalTarget->Pitch(), 0.5_rad);
        ASSERT_TRUE(command.LampIntensity.has_value());
        EXPECT_EQ(command.LampIntensity->Intensity(), NormalizedFraction(0.70));
        ASSERT_TRUE(command.VideoControl.has_value());
        ASSERT_TRUE(command.VideoControl->IsEnabled());
        const auto* enabledVideo = command.VideoControl->TryGetEnabled();
        ASSERT_NE(enabledVideo, nullptr);
        EXPECT_EQ(enabledVideo->Profile, Control::Video::Api::StreamProfile::Standard);
        EXPECT_TRUE(std::holds_alternative<Control::Video::Api::AutoFocus>(enabledVideo->Focus));
        ASSERT_TRUE(command.ModeRequest.has_value());
        EXPECT_TRUE(command.ModeRequest->Is<Mode::HoldPosition>());
    }
}
