/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: IPlugin.hpp
 */

#pragma once

namespace Audio
{
    class IPlugin;

    // using DLLSignature =
};

class Audio::IPlugin
{
public:
    enum class Flags {
        AudioInput      = 1,
        AudioOutput     = 1 << 1,
        NoteInput       = 1 << 2,
        NoteOutput      = 1 << 3,
        ControlInput    = 1 << 4,
        ControlOutput   = 1 << 5,
        SyncInput       = 1 << 6,
        SyncOutput      = 1 << 7,
    };

};