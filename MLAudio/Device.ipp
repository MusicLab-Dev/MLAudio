/**
 * @ Author: Pierre Veysseyre
 * @ Description: Device
 */

inline bool Audio::Device::setSampleRate(const int sampleRate) noexcept
{
    if (sampleRate == _sampleRate)
        return false;
    _sampleRate = sampleRate;
    return true;
}

inline bool Audio::Device::setFormat(const Device::Format format) noexcept
{
    if (format == _format)
        return false;
    _format = format;
    return true;
}

inline bool Audio::Device::setMidiChannels(const MidiChannels midiChannels) noexcept
{
    if (midiChannels == _midiChannels)
        return false;
    _midiChannels = midiChannels;
    return true;
}

inline bool Audio::Device::setBlockSize(const std::uint16_t blockSize) noexcept
{
    if (blockSize == _blockSize)
        return false;
    _blockSize = blockSize;
    return true;
}
