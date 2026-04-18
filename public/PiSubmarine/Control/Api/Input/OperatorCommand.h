#pragma once

#include <optional>

#include "PiSubmarine/Control/Api/Input/Gimbal.h"
#include "PiSubmarine/Control/Api/Input/Horizontal.h"
#include "PiSubmarine/Control/Api/Input/Lamp.h"
#include "PiSubmarine/Control/Api/Input/Mode/Request.h"
#include "PiSubmarine/Control/Api/Input/Vertical.h"

namespace PiSubmarine::Control::Api::Input
{
	struct OperatorCommand
	{
		Horizontal Movement = Horizontal::Create(0, 0).value();
		Vertical VerticalControl = Vertical::KeepCurrentValue();
		std::optional<Gimbal> GimbalTarget;
		std::optional<Lamp> LampIntensity;
		std::optional<Mode::Request> ModeRequest;

		[[nodiscard]] bool operator==(const OperatorCommand&) const = default;
	};
}
