/**
 * @ Author: Pierre Veysseyre
 * @ Description: NoteManager implementation
 */

inline void Audio::NoteManager::processNotes(const Notes &notes) noexcept
{
    for (auto &note : notes) {
        _cache[note.key].active = (note.type == Note::EventType::On);
    }
}

inline void Audio::NoteManager::resetCache(void) noexcept
{
    for (auto &note : _cache)
        note.active = false;
}

inline Audio::NoteManager::ActiveNotes Audio::NoteManager::getActiveNotes(void) const noexcept
{
    ActiveNotes activeNotes;

    for (auto &note : _cache) {
        if (note.active)
            activeNotes.push(note);
    }
    return activeNotes;
}