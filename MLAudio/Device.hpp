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

    // Forward declaration to the SDL audio callback function signature
    using AudioCallback = SDL_AudioCallback;
};


/** @brief Device represent an SDL audio device, it can be used either for input OR output */
class alignas_half_cacheline Audio::Device
{
public:

    /** @brief Format describe the bit depth (e.g. Audio headroom) of the Device
     *  Note that the CPU works increase with the size of the format ! */
    enum class Format : std::uint8_t {
        Fixed8, Fixed16, Fixed32, Floating32
    };

    /** @brief Descibes how to use a logical device and is used to retreive one */
    struct alignas_cacheline Descriptor
    {
        std::string     name { nullptr };
        bool            isInput { true };
        int             sampleRate { 48000 };
        Format          format { Format::Floating32 };
        MidiChannels        midiChannels { 2u };
        std::uint16_t   blockSize { 2048u };
    };

    /** @brief A list of logical device descriptors used to introspect the hardware device */
    using Descriptors = std::vector<Descriptor>;

    /** @brief Construct a device using a descriptor */
    Device(const Descriptor &descriptor, AudioCallback &&callback);

    /** @brief Destroy and release the audio device */
    ~Device(void);


    /** @brief Register the audio callback */
    void start(void) { SDL_PauseAudioDevice(_deviceID, false); }

    /** @brief Unregister the audio callback */
    void stop(void) { SDL_PauseAudioDevice(_deviceID, true); }

    /** @brief Check if the device is running (and audio callback is registered) */
    [[nodiscard]] bool running(void) const noexcept { return (SDL_GetAudioDeviceStatus(_deviceID) == SDL_AUDIO_PLAYING); }


    /** @brief Get the actual sample rate */
    [[nodiscard]] int sampleRate(void) const noexcept { return _sampleRate; }

    /** @brief Set the sample rate, return true if the value changed */
    bool setSampleRate(const int sampleRate) noexcept;


    /** @brief Get the actual format */
    [[nodiscard]] Format format(void) const noexcept { return _format; }

    /** @brief Set the format, return true if the value changed */
    bool setFormat(const Format format) noexcept;


    /** @brief Get the actual midiChannels */
    [[nodiscard]] ChannelArrangement channelArrangement(void) const noexcept { return _channelArrangement; }

    /** @brief Set the channelArrangement, return true if the value changed */
    bool setChannelArrangement(const ChannelArrangement channelArrangement) noexcept;


    /** @brief Get the actual audio block size */
    [[nodiscard]] std::uint16_t blockSize(void) const noexcept { return _blockSize; }

    /** @brief Set the audio block size, return true if the value changed */
    bool setBlockSize(const std::uint16_t blockSize) noexcept;


    /** @brief Initialize the backend audio driver */
    static void InitDriver(void);

    /** @brief Release the backend audio driver */
    static void ReleaseDriver(void);

    /** @brief Get all device descriptors */
    static Descriptors GetDeviceDescriptors(void);

private:
    SDL_AudioDeviceID   _deviceID { 0u };
    AudioCallback       _callback { nullptr };
    int                 _sampleRate { 48000 };
    Format              _format { Format::Floating32 };
    ChannelArrangement  _channelArrangement { ChannelArrangement::Stereo };
    std::uint16_t       _blockSize { 2084u };
};

#include "Device.ipp"

static_assert_fit_half_cacheline(Audio::Device);
