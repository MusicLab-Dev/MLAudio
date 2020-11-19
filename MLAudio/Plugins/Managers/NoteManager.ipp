/**
 * @ Author: Pierre Veysseyre
 * @ Description: NoteManager implementation
 */

inline void Audio::NoteManager::processNotes(const Notes &notes) noexcept
{
    for (auto &note : notes) {
        _cache[note.key].key = note.key;
        _cache[note.key].active = (note.type == Note::EventType::On);
        _cache[note.key].velocity = note.velocity;
        _cache[note.key].tunning = note.tunning;
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