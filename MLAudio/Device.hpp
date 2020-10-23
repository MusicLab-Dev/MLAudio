/**
 * @ Author: Pierre Veysseyre
 * @ Description: Device
 */

#pragma once

#include <memory>
#include <string>

#include <SDL2/SDL.h>

#include "Base.hpp"

namespace Audio
{
    class Device;
    struct Capabilities;

    // Forward declaration to the SDL audio callback function signature
    using AudioCallback = SDL_AudioCallback;

    using DevicePtr = std::unique_ptr<Device>;
};


/** @brief Capabilities describe the device behaviors */
struct Audio::Capabilities
{
    using DeviceCapabilities = std::vector<Capabilities>;
    using NameStr = std::unique_ptr<char *>;

    NameStr     name { nullptr };
    bool        isInput { true };
};

/** @brief Device represent an SDL audio device, it can be used either for input OR output */
class Audio::Device
{
public:
    /** @brief Format describe the bit depth (e.g. Audio headroom) of the Device
     *  Note that the CPU works increase with the size of the format ! */
    enum class Format : std::uint8_t {
        Fixed8, Fixed16, Fixed32, Floating32
    };


    Device(const std::string_view &name, AudioCallback &&callback);


    void init(void);
    void release(void);
    void start(void);
    void stop(void);


    /** @brief Get the actual sample rate */
    [[nodiscard]] int sampleRate(void) const noexcept { return _sampleRate; }

    /** @brief Set the sample rate, return true if the value changed */
    bool setSampleRate(const int sampleRate) noexcept;


    /** @brief Get the actual format */
    [[nodiscard]] Format format(void) const noexcept { return _format; }

    /** @brief Set the format, return true if the value changed */
    bool setFormat(const Format format) noexcept;


    /** @brief Get the actual channels */
    [[nodiscard]] Channels channels(void) const noexcept { return _channels; }

    /** @brief Set the channels, return true if the value changed */
    bool setChannels(const Channels channels) noexcept;


    /** @brief Get the actual audio block size */
    [[nodiscard]] std::uint16_t blockSize(void) const noexcept { return _blockSize; }

    /** @brief Set the audio block size, return true if the value changed */
    bool setBlockSize(const std::uint16_t blockSize) noexcept;


    static void Release(void);

    static Capabilities::DeviceCapabilities GetDeviceCapabilities(void);

    static DevicePtr Instantiate(const char *name);

private:
    AudioCallback   _callback { nullptr };
    int             _sampleRate { 48000 };
    Format          _format { Format::Floating32 };
    Channels        _channels { 2u };
    std::uint16_t   _blockSize { 2084u };
};

#include "Device.ipp"

// static_assert(alignof(Audio::Device) == 16, "Device must be aligned to 16 bytes !");
static_assert(sizeof(Audio::Device) == 16, "Device must take 16 bytes !");
