/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: IPlugin.hpp
 */

#pragma once

#include "Buffer.hpp"
#include "Control.hpp"
#include "Note.hpp"
#include "IPluginFactory.hpp"

namespace Audio
{
    class IPlugin;
};

class Audio::IPlugin
{
public:
    using Flags = IPluginFactory::Flags;

    /** @brief Virtual destructor */
    virtual ~IPlugin(void) noexcept = default;

    // virtual ParameterDescriptors getParameterDescriptors(void) const = 0;

    static PluginFactoryPtr GetFactory(void);
    static void SetFactory(PluginFactoryPtr factory);

    Flags getFlags(void);

    virtual bool hasAudioInput(void) const = 0;
    virtual bool hasAudioOutput(void) const = 0;
    virtual void sendAudio(const Buffers &inputs) = 0;
    virtual bool receiveAudio(Buffers &outputs) = 0;

    virtual bool hasNoteInput(void) const = 0;
    virtual bool hasNoteOutput(void) const = 0;
    virtual void sendNotes(const Notes &notes) = 0;
    virtual bool receiveNotes(Notes &notes) = 0;

    virtual bool hasControlInput(void) const = 0;
    virtual bool hasControlOutput(void) const = 0;
    virtual bool sendControls(const Controls &controls) = 0;
    virtual bool receiveControls(Controls &controls) = 0;

    virtual bool hasSyncInput(void) const = 0;
    virtual bool hasSyncOutput(void) const = 0;
    virtual void sendSync(const Tempo &tempo) = 0;
    virtual bool receiveSync(Tempo &tempo) = 0;

    virtual void onAudioGenerationStarted(const TimeRange &range) = 0;
    virtual void onAudioGenerationStopped(void) = 0;
    virtual void onAudioBlockGenerated(void) = 0;
};
