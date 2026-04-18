#pragma once

namespace PiSubmarine::Control::Api::Input::Mode
{
	struct HoldPosition
	{
		[[nodiscard]] constexpr bool operator==(const HoldPosition&) const = default;
	};
}