#pragma once

#include <variant>
#include <PiSubmarine/Control/Api/Input/Mode/HoldPosition.h>
#include <PiSubmarine/Control/Api/Input/Mode/Manual.h>

namespace PiSubmarine::Control::Api::Input::Mode
{
	class Request
	{
	public:
		using Value = std::variant<Manual, HoldPosition>;

		[[nodiscard]] static constexpr Request ManualValue() noexcept
		{
			return Request(Manual{});
		}

		[[nodiscard]] static constexpr Request HoldPositionValue() noexcept
		{
			return Request(HoldPosition{});
		}

		[[nodiscard]] constexpr const Value& Get() const noexcept
		{
			return m_Value;
		}

		template <typename T>
		[[nodiscard]] constexpr bool Is() const noexcept
		{
			return std::holds_alternative<T>(m_Value);
		}

		template <typename T>
		[[nodiscard]] constexpr const T* TryGet() const noexcept
		{
			return std::get_if<T>(&m_Value);
		}

		[[nodiscard]] constexpr bool operator==(const Request&) const = default;

	private:
		constexpr explicit Request(const Value& value) noexcept
			: m_Value(value)
		{
		}

		Value m_Value;
	};
}
