/**
 * @ Author: Pierre Veysseyre
 * @ Description: Partition
 */

#pragma once

#include "Note.hpp"

namespace Audio
{
    class Partition;

    using Partitions = Core::FlatVector<Partition>;
};

class Audio::Partition
{
public:
    /** @brief Get the internal notes */
    [[nodiscard]] inline const Notes &notes(void) const noexcept { return _notes; }

    /** @brief Get the internal notes */
    [[nodiscard]] inline Notes &notes(void) noexcept { return _notes; }

    /** @brief Get the internal notes count */
    [[nodiscard]] inline std::size_t count(void) const noexcept { return _notes.size(); }


    /** @brief Get the internal intances */
    [[nodiscard]] TimeRanges &instances(void) noexcept { return _instances; }

    /** @brief Set the internal intances */
    [[nodiscard]] const TimeRanges &instances(void) const noexcept { return _instances; }


    /** @brief Check if the partition is muted (not active) or not */
    [[nodiscard]] bool muted(void) const noexcept { return _muted; }

    /** @brief Set the muted state of the partition */
    bool setMuted(const bool muted) noexcept;


    /** @brief Get the internal channels */
    [[nodiscard]] Channels channels(void) const noexcept { return _channel; }

    /** @brief Set the internal channels */
    bool setChannels(const Channels channels) noexcept;


    /** @brief Get the name of the partition */
    [[nodiscard]] const Core::FlatString &name(void) const noexcept { return _name; }

    /** @brief Set the partition name, return true if the name changed */
    bool setName(Core::FlatString &&name) noexcept;


    template<typename Functor>
    bool apply(const TimeRange &range, Functor &&functor) noexcept;

private:
    Notes               _notes {};
    TimeRanges          _instances {};
    Core::FlatString    _name {};
    NoteIndex           _lastID {};
    Channels            _channel { 0u };
    bool                _muted { false };
};

#include "Partition.ipp"

static_assert(sizeof(Audio::Partition) == 32, "Partition must take 32 bytes !");
