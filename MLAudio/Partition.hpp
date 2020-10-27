/**
 * @ Author: Pierre Veysseyre
 * @ Description: Partition
 */

#pragma once

#include "Note.hpp"

namespace Audio
{
    class Partition;

    using Partitions = FlatVector<Partition>;
};

class Audio::Partition
{
public:
    /** @brief Get the internal notes */
    [[nodiscard]] const Notes &notes(void) const noexcept { return _notes; }

    /** @brief Get the internal notes count */
    [[nodiscard]] std::size_t count(void) const noexcept;


    /** @brief Add a single note to the partition */
    void add(const Note &note) noexcept;

    /** @brief Add multiple notes to the partition */
    void add(const Notes &notes) noexcept;

    /** @brief Replace actual notes by another ones to the partition */
    void replace(const Notes &notes) noexcept;


    /** @brief Get the internal notes count */
    bool remove(const size_t index) noexcept;

    /** @brief Get the internal notes count */
    bool remove(const TimeRange &range) noexcept;


    /** @brief Get a note at a specified index (throw if invalid index ?) */
    [[nodiscard]] Note &get(const size_t index);

    /** @brief Set a note at a specified index (throw if invalid index ?) */
    [[nodiscard]] const Note &get(const size_t index) const;


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
    [[nodiscard]] const CustomString &name(void) const noexcept { return _name; }

    /** @brief Set the partition name, return true if the name changed */
    bool setName(CustomString &&name) noexcept;


    template<typename Functor>
    bool apply(const TimeRange &range, Functor &&functor) noexcept;

private:
    Notes           _notes {};
    TimeRanges      _instances {};
    CustomString    _name {};
    NoteIndex       _lastID {};
    Channels         _channel {};
    bool            _muted { false };
};

#include "Partition.ipp"

static_assert(sizeof(Audio::Partition) == 32, "Partition must take 32 bytes !");
