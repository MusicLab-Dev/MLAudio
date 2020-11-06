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

    virtual Flags getFlags(void) const noexcept = 0;

    virtual bool hasAudioInput(void) const noexcept = 0;
    virtual bool hasAudioOutput(void) const noexcept = 0;
    virtual bool receiveAudio(const Buffers &outputs) = 0;
    virtual void sendAudio(Buffers &inputs) = 0;

    virtual bool hasNoteInput(void) const noexcept = 0;
    virtual bool hasNoteOutput(void) const noexcept = 0;
    virtual bool receiveNotes(const Notes &notes) = 0;
    virtual void sendNotes(Notes &notes) = 0;

    virtual bool hasControlInput(void) const noexcept = 0;
    virtual bool hasControlOutput(void) const noexcept = 0;
    virtual bool receiveControls(const Controls &controls) = 0;
    virtual bool sendControls(Controls &controls) = 0;

    virtual bool hasSyncInput(void) const noexcept = 0;
    virtual bool hasSyncOutput(void) const noexcept = 0;
    virtual bool receiveSync(const Tempo &tempo) = 0;
    virtual void sendSync(Tempo &tempo) = 0;

    virtual void onAudioGenerationStarted(const TimeRange &range) = 0;
    virtual void onAudioGenerationStopped(void) = 0;
    virtual void onAudioBlockGenerated(void) = 0;
};
