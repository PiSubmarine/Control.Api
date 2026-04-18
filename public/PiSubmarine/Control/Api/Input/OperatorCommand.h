#pragma once

#include <optional>

#include "PiSubmarine/Control/Api/Input/Mode/Request.h"
#include "PiSubmarine/Control/Gimbal/Api/Command.h"
#include "PiSubmarine/Control/Horizontal/Api/Command.h"
#include "PiSubmarine/Control/Lamp/Api/Command.h"
#include "PiSubmarine/Control/Vertical/Api/Command.h"

namespace PiSubmarine::Control::Api::Input
{
	struct OperatorCommand
	{
		Control::Horizontal::Api::Command Movement = Control::Horizontal::Api::Command::Create(0, 0).value();
		Control::Vertical::Api::Command VerticalControl = Control::Vertical::Api::Command::KeepCurrentValue();
		std::optional<Control::Gimbal::Api::Command> GimbalTarget;
		std::optional<Control::Lamp::Api::Command> LampIntensity;
		std::optional<Mode::Request> ModeRequest;

		[[nodiscard]] bool operator==(const OperatorCommand&) const = default;
	};
}
