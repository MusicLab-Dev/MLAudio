/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: Globals.hpp
 */

#include <cstdint>

namespace ML::Audio
{
    using Beat = uint32_t;
    using Tempo = float;
    using TimeIndex = uint32_t;
    using Color = uint32_t;
    using NoteIndex = uint16_t;
    using Key = uint8_t;
    using Velocity = uint16_t;
    using ParamID = uint32_t;
    using ParamValue = double;
    using Tuning = float;
    using Channels = uint8_t;

    struct BeatRange;
    struct TimeRange;
};

struct ML::Audio::BeatRange {
    Beat from {};
    Beat to {};
};

struct ML::Audio::TimeRange {
    TimeIndex from {};
    TimeIndex to {};
};

static_assert(sizeof(ML::Audio::BeatRange) == 8, "BeatRange must take 8 bytes !");
static_assert(sizeof(ML::Audio::TimeRange) == 8, "TimeRange must take 8 bytes !");