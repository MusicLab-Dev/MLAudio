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

inline bool Audio::Device::setChannel(const Channel channels) noexcept
{
    if (channels == _channels)
        return false;
    _channels = channels;
    return true;
}

inline bool Audio::Device::setBlockSize(const std::uint16_t blockSize) noexcept
{
    if (blockSize == _blockSize)
        return false;
    _blockSize = blockSize;
    return true;
}
