/**
 * @ Author: Pierre Veysseyre
 * @ Description: Note
 */

#pragma once

#include <cstdint>

#include "Base.hpp"

namespace Audio
{
    struct Note;

    using Notes =Core::FlatVector<Note>;
};

struct Audio::Note
{
    enum class EventType : std::uint8_t {
        On, Off, PolyPressure
    };

    BeatRange   range {};
    EventType   type {};
    Key         key {};
    Velocity    velocity {};
    Tuning      tunning { 0u };
    NoteIndex   noteIndex {};
};

static_assert(sizeof(Audio::Note) == 16, "Note must take 16 bytes !");
