/**
 * @ Author: Pierre Veysseyre
 * @ Description: Partition
 */

inline bool Audio::Partition::setMuted(const bool muted) noexcept
{
    if (muted == _muted)
        return false;
    _muted = muted;
    return true;
}

inline bool Audio::Partition::setChannels(const Channels channels) noexcept
{
    if (channels == _channel)
        return false;
    _channel = channels;
    return true;
}

inline bool Audio::Partition::setName(CustomString &&name) noexcept
{
    if (name == _name)
        return false;
    _name = std::move(name);
    return true;
}