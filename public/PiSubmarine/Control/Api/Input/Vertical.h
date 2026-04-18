#pragma once

#include <variant>

#include "PiSubmarine/Meters.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Control::Api::Input
{
    class Vertical
    {
    public:
        struct KeepCurrent
        {
            [[nodiscard]] constexpr bool operator==(const KeepCurrent&) const = default;
        };

        struct SetDepthTarget
        {
            Meters Depth;

            [[nodiscard]] constexpr bool operator==(const SetDepthTarget& other) const noexcept
            {
                return Depth.Value == other.Depth.Value;
            }
        };

        struct SetBallastPosition
        {
            NormalizedFraction Position;

            [[nodiscard]] constexpr bool operator==(const SetBallastPosition&) const = default;
        };

        using Value = std::variant<KeepCurrent, SetDepthTarget, SetBallastPosition>;

        [[nodiscard]] static constexpr Vertical KeepCurrentValue() noexcept
        {
            return Vertical(KeepCurrent{});
        }

        [[nodiscard]] static constexpr Vertical SetDepthTargetTo(const Meters depth) noexcept
        {
            return Vertical(SetDepthTarget{depth});
        }

        [[nodiscard]] static constexpr Vertical SetBallastPositionTo(const NormalizedFraction position) noexcept
        {
            return Vertical(SetBallastPosition{position});
        }

        [[nodiscard]] constexpr const Value& Get() const noexcept
        {
            return m_Value;
        }

        template<typename T>
        [[nodiscard]] constexpr bool Is() const noexcept
        {
            return std::holds_alternative<T>(m_Value);
        }

        template<typename T>
        [[nodiscard]] constexpr const T* TryGet() const noexcept
        {
            return std::get_if<T>(&m_Value);
        }

        [[nodiscard]] constexpr bool operator==(const Vertical&) const = default;

    private:
        constexpr explicit Vertical(const Value& value) noexcept
            : m_Value(value)
        {
        }

        Value m_Value;
    };
}
