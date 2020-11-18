/**
 * @ Author: Pierre Veysseyre
 * @ Description: NoteManager
 */

#pragma once

#include "Note.hpp"

namespace Audio
{
    class NoteManager;
};

class Audio::NoteManager
{
public:
    static constexpr auto CacheSize = std::numeric_limits<Key>::max();

    // void addNote

private:
    Note        _cache[CacheSize];
};
