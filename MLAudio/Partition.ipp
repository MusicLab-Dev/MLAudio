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

inline bool Audio::Partition::setChannels(const channels channels) noexcept
{
    if (channels == _channels)
        return false;
    _channels = channels;
    return true;
}

inline bool Audio::Partition::setName(CustomString &&name) noexcept
{
    if (name == _name)
        return false;
    _name = std::move(name);
    return true;
}