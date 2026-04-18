#pragma once

#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Control::Api::Input
{
    class Lamp
    {
    public:
        [[nodiscard]] static constexpr Lamp Create(const NormalizedFraction intensity) noexcept
        {
            return Lamp(intensity);
        }

        [[nodiscard]] constexpr NormalizedFraction Intensity() const noexcept
        {
            return m_Intensity;
        }

        [[nodiscard]] constexpr bool operator==(const Lamp&) const = default;

    private:
        constexpr explicit Lamp(const NormalizedFraction intensity) noexcept
            : m_Intensity(intensity)
        {
        }

        NormalizedFraction m_Intensity;
    };
}
