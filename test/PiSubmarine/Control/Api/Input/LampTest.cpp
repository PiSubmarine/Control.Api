#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/Lamp.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(LampTest, CreateStoresIntensity)
    {
        constexpr auto lamp = Lamp::Create(NormalizedFraction(0.65));

        static_assert(lamp.Intensity() == NormalizedFraction(0.65));
        EXPECT_EQ(lamp.Intensity(), NormalizedFraction(0.65));
    }
}
