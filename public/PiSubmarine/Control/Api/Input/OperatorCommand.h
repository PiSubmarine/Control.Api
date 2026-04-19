#pragma once

#include <optional>

#include "PiSubmarine/Control/Api/Input/Mode/Request.h"
#include "PiSubmarine/Control/Gimbal/Api/Command.h"
#include "PiSubmarine/Control/Horizontal/Api/Command.h"
#include "PiSubmarine/Control/Lamp/Api/Command.h"
#include "PiSubmarine/Control/Vertical/Api/Command.h"
#include "PiSubmarine/Control/Video/Api/Command.h"
#include "PiSubmarine/Lease/Api/Identifiers.h"

namespace PiSubmarine::Control::Api::Input
{
	struct OperatorCommand
	{
		Lease::Api::LeaseId LeaseId;
		Control::Horizontal::Api::Command Movement = Control::Horizontal::Api::Command::Create(0, 0).value();
		Control::Vertical::Api::Command VerticalControl = Control::Vertical::Api::Command::KeepCurrentValue();
		std::optional<Control::Gimbal::Api::Command> GimbalTarget;
		std::optional<Control::Lamp::Api::Command> LampIntensity;
		std::optional<Control::Video::Api::Command> VideoControl;
		std::optional<Mode::Request> ModeRequest;

		[[nodiscard]] bool operator==(const OperatorCommand&) const = default;
	};
}
