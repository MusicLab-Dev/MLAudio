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

    using AudioCallback = SDL_AudioCallback;

    using DevicePtr = std::unique_ptr<Device>;
};

class Audio::Device
{
public:
    enum class Format : std::uint8_t {
        Fixed8, Fixed16, Fixed32, Floating32
    };

    Device(const std::string_view &name, AudioCallback &&callback);

    void release(void);
    void start(void);
    void stop(void);

    int sampleRate(void) const noexcept { return _sampleRate; }
    bool setSampleRate(int sampleRate) noexcept; // --> .ipp



private:
    AudioCallback   _callback { nullptr };
    int             _sampleRate { 48000 };
    Format          _format { Format::Floating32 };
    Channels        _channels { 2u };
    std::uint16_t   _blockSize { 2084u }
};