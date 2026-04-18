#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/Vertical.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(VerticalTest, KeepCurrentCreatesKeepCurrentValue)
    {
        constexpr auto vertical = Vertical::KeepCurrentValue();

        static_assert(vertical.Is<Vertical::KeepCurrent>());
        EXPECT_TRUE(vertical.Is<Vertical::KeepCurrent>());
        EXPECT_NE(vertical.TryGet<Vertical::KeepCurrent>(), nullptr);
    }

    TEST(VerticalTest, SetDepthTargetStoresDepth)
    {
        constexpr auto vertical = Vertical::SetDepthTargetTo(2.5_m);

        static_assert(vertical.Is<Vertical::SetDepthTarget>());
        const auto* depthTarget = vertical.TryGet<Vertical::SetDepthTarget>();

        ASSERT_NE(depthTarget, nullptr);
        EXPECT_EQ(depthTarget->Depth.Value, 2.5);
    }

    TEST(VerticalTest, SetBallastPositionStoresPosition)
    {
        const auto vertical = Vertical::SetBallastPositionTo(NormalizedFraction(0.75));
        const auto* ballastPosition = vertical.TryGet<Vertical::SetBallastPosition>();

        ASSERT_NE(ballastPosition, nullptr);
        EXPECT_EQ(static_cast<double>(ballastPosition->Position), 0.75);
    }
}
