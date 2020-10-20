/*
 * @ Author: Pierre Veysseyre
 * @ Description: A collection of Audio library builtins
 */

#include <cstdint>

namespace Audio
{
    using Beat = std::uint32_t;
    using Tempo = float;
    using TimeIndex = std::uint32_t;
    using Color = std::uint32_t;
    using NoteIndex = std::uint16_t;
    using Key = std::uint8_t;
    using Velocity = std::uint16_t;
    using ParamID = std::uint32_t;
    using ParamValue = double;
    using Tuning = float;
    using Channels = std::uint8_t;

    struct BeatRange;
    struct TimeRange;
};

struct Audio::BeatRange
{
    Beat from {};
    Beat to {};
};

struct Audio::TimeRange
{
    TimeIndex from {};
    TimeIndex to {};
};

static_assert(sizeof(Audio::BeatRange) == 8, "BeatRange must take 8 bytes !");
static_assert(sizeof(Audio::TimeRange) == 8, "TimeRange must take 8 bytes !");