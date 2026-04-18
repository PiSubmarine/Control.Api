#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/Input/Mode/Request.h"

namespace PiSubmarine::Control::Api::Input::Mode
{
    TEST(RequestTest, ManualValueCreatesManualRequest)
    {
        constexpr auto request = Request::ManualValue();

        static_assert(request.Is<Manual>());
        EXPECT_TRUE(request.Is<Manual>());
        EXPECT_NE(request.TryGet<Manual>(), nullptr);
    }

    TEST(RequestTest, HoldPositionValueCreatesHoldPositionRequest)
    {
        constexpr auto request = Request::HoldPositionValue();

        static_assert(request.Is<HoldPosition>());
        EXPECT_TRUE(request.Is<HoldPosition>());
        EXPECT_NE(request.TryGet<HoldPosition>(), nullptr);
    }
}
