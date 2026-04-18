#pragma once

#include "PiSubmarine/Radians.h"

namespace PiSubmarine::Control::Api::Input
{
    class Gimbal
    {
    public:
        [[nodiscard]] static constexpr Gimbal Create(const Radians pitch) noexcept
        {
            return Gimbal(pitch);
        }

        [[nodiscard]] constexpr Radians Pitch() const noexcept
        {
            return m_Pitch;
        }

        [[nodiscard]] constexpr bool operator==(const Gimbal&) const = default;

    private:
        constexpr explicit Gimbal(const Radians pitch) noexcept
            : m_Pitch(pitch)
        {
        }

        Radians m_Pitch;
    };
}
