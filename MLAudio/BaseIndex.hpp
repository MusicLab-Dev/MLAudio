/**
 * @ Author: Pierre Veysseyre
 * @ Description: Base Ranges
 */

#pragma once

#include <cstdint>

namespace Audio
{
    /** @brief Beat index */
    using Beat = std::uint32_t;

    /** @brief Time index */
    using TimeIndex = std::uint32_t;

    struct BeatRange;
    struct TimeRange;
}


/** @brief Beat range */
struct alignas(8) BeatRange
{
    Beat from {};
    Beat to {};

    [[nodiscard]] inline bool operator==(const BeatRange &other) const noexcept { return (from == other.from) && (to == other.to); }
    [[nodiscard]] inline bool operator!=(const BeatRange &other) const noexcept { return !(operator==(other)); }
};

static_assert_fit(Audio::BeatRange, 8);

/** @brief Time range */
struct alignas(8) TimeRange
{
    TimeIndex from {};
    TimeIndex to {};

    [[nodiscard]] inline bool operator==(const TimeRange &other) const noexcept { return (from == other.from) && (to == other.to); }
    [[nodiscard]] inline bool operator!=(const TimeRange &other) const noexcept { return !(operator==(other)); }
};

static_assert_fit(Audio::TimeRange, 8);
