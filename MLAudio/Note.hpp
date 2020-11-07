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
    [[nodiscard]] inline bool operator==(const Note &other) const noexcept;

    /** @brief Check if an another note is different */
    [[nodiscard]] inline bool operator!=(const Note &other) const noexcept;

    /** @brief Check if this note come after an another one */
    [[nodiscard]] inline bool operator>(const Note &other) const noexcept;

    /** @brief Check if this note come after an another one or in same time */
    [[nodiscard]] inline bool operator>=(const Note &other) const noexcept;

    /** @brief Check if this note come before an another one */
    [[nodiscard]] inline bool operator<(const Note &other) const noexcept;

    /** @brief Check if this note come before an another one or in same time */
    [[nodiscard]] inline bool operator<=(const Note &other) const noexcept;

    BeatRange   range {};
    EventType   type {};
    Key         key {};
    Velocity    velocity {};
    Tuning      tunning { 0u };
    NoteIndex   noteIndex {};
};

#include "Note.ipp"

static_assert(sizeof(Audio::Note) == 16, "Note must take 16 bytes !");
