#pragma once

#include <system_error>

namespace PiSubmarine::Control::Api
{
    enum class ErrorCode
    {
        HorizontalMagnitudeExceeded = 1
    };

    [[nodiscard]] std::error_code make_error_code(ErrorCode errorCode) noexcept;
}

namespace std
{
    template<>
    struct is_error_code_enum<PiSubmarine::Control::Api::ErrorCode> : true_type
    {
    };
}
