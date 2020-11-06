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

    using Notes = Core::FlatVector<Note>;
};

struct Audio::Note
{
    enum class EventType : std::uint8_t {
        On, Off, PolyPressure
    };

    /** @brief Check if an another note is the same */
    [[nodiscard]] inline bool operator==(const Note &other) const noexcept {
        return (
            (range == other.range) &&
            (type == other.type) &&
            (key == other.key) &&
            (velocity == other.velocity) &&
            (tunning == other.tunning) &&
            (noteIndex == other.noteIndex)
        );
    }

    [[nodiscard]] inline bool operator!=(const Note &other) const noexcept { return !(operator==(other)); }

    [[nodiscard]] inline bool operator>(const Note &other) const noexcept {

    }

    BeatRange   range {};
    EventType   type {};
    Key         key {};
    Velocity    velocity {};
    Tuning      tunning { 0u };
    NoteIndex   noteIndex {};
};

static_assert(sizeof(Audio::Note) == 16, "Note must take 16 bytes !");
