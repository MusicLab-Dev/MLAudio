/*
 * @ Author: Pierre Veysseyre
 * @ Description: A collection of Audio library builtins
 */

#pragma once

#include <cstdint>

#include <MLCore/Vector.hpp>
#include <MLCore/FlatVector.hpp>
#include <MLCore/FlatString.hpp>

#include "BaseIndex.hpp"

namespace Core
{
    template<typename Type>
    using SortedVector = Vector<Type>;

    template<typename Type>
    using SortedFlatVector = FlatVector<Type>;
}

namespace Audio
{
    using Tempo = float;
    using Color = std::uint32_t;
    using NoteIndex = std::uint16_t;
    using Key = std::uint8_t;
    using Velocity = std::uint16_t;
    using ParamID = std::uint32_t;
    using ParamValue = double;
    using Tuning = uint16_t;
    using Channels = std::uint8_t;


    using BeatRanges = Core::SortedFlatVector<BeatRange>;
    using TimeRanges = Core::SortedFlatVector<TimeRange>;
};

static_assert(sizeof(Audio::BeatRange) == 8, "BeatRange must take 8 bytes !");
static_assert(sizeof(Audio::TimeRange) == 8, "TimeRange must take 8 bytes !");