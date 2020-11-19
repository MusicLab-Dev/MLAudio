/**
 * @ Author: Pierre Veysseyre
 * @ Description: NoteManager
 */

#pragma once

#include <array>
#include <memory>

#include "../../Note.hpp"
#include "../../FlatNote.hpp"

namespace Audio
{
    class NoteManager;

    using NoteManagerPtr = std::unique_ptr<NoteManager>;
};

class Audio::NoteManager
{
public:
    /** @brief Max cache size, deduced from Key type */
    static constexpr auto CacheSize = std::numeric_limits<Key>::max() + 1;

    /** @brief Describe the internal cache */
    using FlatNotes = std::array<FlatNote, CacheSize>;
    using ActiveNotes = Core::TinyVector<FlatNote>;


    /** @brief Process a list of notes and update the internal cache */
    void processNotes(const Notes &notes) noexcept;

    /** @brief Get the actual active notes */
    [[nodiscard]] ActiveNotes getActiveNotes(void) const noexcept;

    /** @brief Reset the internal cache. All notes are turned off */
    void resetCache(void) noexcept;


private:
    FlatNotes   _cache {};
};

static_assert_sizeof(Audio::NoteManager, (sizeof(Audio::FlatNote) * Audio::NoteManager::CacheSize));

#include "NoteManager.ipp"
