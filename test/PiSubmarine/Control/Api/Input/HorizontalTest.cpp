#include <gtest/gtest.h>

#include "PiSubmarine/Control/Api/ErrorCode.h"
#include "PiSubmarine/Control/Api/Input/Horizontal.h"

namespace PiSubmarine::Control::Api::Input
{
    TEST(HorizontalTest, CreateAcceptsUnitCircleBoundary)
    {
        constexpr auto result = Horizontal::Create(
            SignedNormalizedFraction(0.60),
            SignedNormalizedFraction(0.80));

        static_assert(result.has_value());
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result->Surge(), SignedNormalizedFraction(0.60));
        EXPECT_EQ(result->Yaw(), SignedNormalizedFraction(0.80));
    }

    TEST(HorizontalTest, CreateRejectsValuesOutsideUnitCircle)
    {
        const auto result = Horizontal::Create(
            SignedNormalizedFraction(0.80),
            SignedNormalizedFraction(0.80));

        ASSERT_FALSE(result.has_value());
        EXPECT_EQ(result.error().Condition, Error::Api::ErrorCondition::ContractError);
        EXPECT_EQ(result.error().Cause, make_error_code(ErrorCode::HorizontalMagnitudeExceeded));
    }

    TEST(HorizontalTest, CreateAcceptsPureForwardCommand)
    {
        const auto result = Horizontal::Create(
            SignedNormalizedFraction(1.0),
            SignedNormalizedFraction(0.0));

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result->Surge(), SignedNormalizedFraction(1.0));
        EXPECT_EQ(result->Yaw(), SignedNormalizedFraction(0.0));
    }
}
