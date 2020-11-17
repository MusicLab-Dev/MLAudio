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

    virtual bool receiveAudio(const Buffers &outputs) noexcept = 0;
    virtual void sendAudio(Buffers &inputs) noexcept = 0;

    virtual bool receiveNotes(const Notes &notes) noexcept = 0;
    virtual void sendNotes(Notes &notes) noexcept = 0;

    virtual bool receiveControls(const Controls &controls) noexcept = 0;
    virtual bool sendControls(Controls &controls) noexcept = 0;

    virtual bool receiveSync(const Tempo &tempo) noexcept = 0;
    virtual void sendSync(Tempo &tempo) noexcept = 0;

    virtual void onAudioGenerationStarted(const TimeRange &range) noexcept = 0;
    virtual void onAudioGenerationStopped(void) noexcept = 0;
    virtual void onAudioBlockGenerated(void) noexcept = 0;

    [[nodiscard]] inline bool hasAudioInput(void) const noexcept    { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::AudioInput); }
    [[nodiscard]] inline bool hasAudioOutput(void) const noexcept   { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::AudioOutput); }
    [[nodiscard]] inline bool hasNoteInput(void) const noexcept     { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::NoteInput); }
    [[nodiscard]] inline bool hasNoteOutput(void) const noexcept    { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::NoteOutput); }
    [[nodiscard]] inline bool hasControlInput(void) const noexcept  { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::ControlInput); }
    [[nodiscard]] inline bool hasControlOutput(void) const noexcept { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::ControlOutput); }
    [[nodiscard]] inline bool hasSyncInput(void) const noexcept     { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::SyncInput); }
    [[nodiscard]] inline bool hasSyncOutput(void) const noexcept    { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::SyncOutput); }
};
