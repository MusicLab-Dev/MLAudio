/**
 * @ Author: Pierre Veysseyre
 * @ Description: Base Ranges
 */

#pragma once

#include <cstdint>

namespace Audio
{
    using Beat = std::uint32_t;
    using TimeIndex = std::uint32_t;

    struct BeatRange
    {
        Beat from {};
        Beat to {};

        [[nodiscard]] inline bool operator==(const BeatRange &other) const noexcept { return (from == other.from) && (to == other.to); }
        [[nodiscard]] inline bool operator!=(const BeatRange &other) const noexcept { return !(operator==(other)); }
    };

    struct TimeRange
    {
        TimeIndex from {};
        TimeIndex to {};

        [[nodiscard]] inline bool operator==(const TimeRange &other) const noexcept { return (from == other.from) && (to == other.to); }
        [[nodiscard]] inline bool operator!=(const TimeRange &other) const noexcept { return !(operator==(other)); }
    };

}