#pragma once

namespace PiSubmarine::Control::Api::Input::Mode
{
	struct Manual
	{
		[[nodiscard]] constexpr bool operator==(const Manual&) const = default;
	};
}