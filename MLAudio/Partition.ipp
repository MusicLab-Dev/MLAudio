/**
 * @ Author: Pierre Veysseyre
 * @ Description: Partition implementation
 */

#include <stdexcept>

using namespace Audio;

inline bool Partition::setMuted(const bool muted) noexcept
{
    if (muted == _muted)
        return false;
    _muted = muted;
    return true;
}

inline bool Partition::setMidiChannels(const MidiChannels midiChannels) noexcept
{
    if (midiChannels == _channel)
        return false;
    _channel = midiChannels;
    return true;
}

inline bool Partition::setName(Core::FlatString &&name) noexcept
{
    if (name == _name)
        return false;
    _name = std::move(name);
    return true;
}
