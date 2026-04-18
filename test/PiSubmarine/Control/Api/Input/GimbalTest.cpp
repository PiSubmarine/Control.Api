#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/Gimbal.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(GimbalTest, CreateStoresPitch)
    {
        constexpr auto gimbal = Gimbal::Create(Radians(0.25));

        static_assert(gimbal.Pitch() == Radians(0.25));
        EXPECT_EQ(gimbal.Pitch(), Radians(0.25));
    }
}
