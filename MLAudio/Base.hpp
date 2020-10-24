/*
 * @ Author: Pierre Veysseyre
 * @ Description: A collection of Audio library builtins
 */

#include <cstdint>
#include <vector>
#include <string>

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
    using Tuning = uint16_t;
    using Channels = std::uint8_t;

    struct BeatRange;
    struct TimeRange;

    // Remove those after
    template<typename T>
    using FlatVector = T*;
    using FlatString = FlatVector<char>;

    using BeatRanges = FlatVector<BeatRange>;
    using TimeRanges = FlatVector<TimeRange>;

    // Replace std::string by FlatString
    using CustomString = FlatString;

    // Replace by the 'real' RefCount
    using RefCount = std::uint32_t;
    using RefCounts = FlatVector<RefCount>;
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