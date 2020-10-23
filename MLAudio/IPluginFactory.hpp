/*
 * @ Author: Pierre Veysseyre
 * @ Description: IPluginFactory
 */

#pragma once

#include <memory>

#include "PluginPtr.hpp"

#include "Base.hpp"

namespace Audio
{
    class IPluginFactory;

    using PluginFactoryPtr = std::unique_ptr<IPluginFactory>;

    using PluginFactories = FlatVector<PluginFactoryPtr>;
};

class Audio::IPluginFactory
{
public:
    enum class SDK : std::uint32_t {
        Internal, External, VST2, VST3
    };
    enum class Tags : std::uint32_t {
        Effect          = 1,
        Analyzer        = 1 << 1,
        Delay           = 1 << 2,
        Distortion      = 1 << 3,
        Dynamics        = 1 << 4,
        EQ              = 1 << 5,
        Filter          = 1 << 6,
        Spatial         = 1 << 7,
        Generator       = 1 << 8,
        Mastering       = 1 << 9,
        Modulation      = 1 << 10,
        PitchShift      = 1 << 11,
        Restoration     = 1 << 12,
        Reverb          = 1 << 13,
        Surround        = 1 << 14,
        Tools           = 1 << 15,
        Network         = 1 << 16,
        Drum            = 1 << 17,
        Instrument      = 1 << 18,
        Drum            = 1 << 19,
        Piano           = 1 << 20,
        Sampler         = 1 << 21,
        Synth           = 1 << 22,
        External        = 1 << 23
    };

    ~IPluginFactory(void) {}

    virtual std::string_view getName(void) = 0;
    virtual std::string_view getPath(void) = 0;
    // virtual Flags getFlags(void) = 0;
    virtual Tags getTags(void) = 0;
    // virtual Capabilities getCapabilities(void) = 0;
    virtual SDK getSDK(void) = 0;
    virtual PluginPtr instantiate(void) = 0;

};