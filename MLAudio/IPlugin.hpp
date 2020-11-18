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

    /** @brief  */
    static PluginFactoryPtr GetFactory(void);
    /** @brief  */
    static void SetFactory(PluginFactoryPtr factory);

    /** @brief  */
    virtual Flags getFlags(void) const noexcept = 0;

    /** @brief  */
    virtual void sendAudio(const BufferViews &inputs) noexcept = 0;
    /** @brief  */
    virtual void receiveAudio(BufferView output) noexcept = 0;

    /** @brief  */
    virtual void sendNotes(const Notes &notes) noexcept = 0;
    /** @brief  */
    virtual void receiveNotes(Notes &notes) noexcept = 0;


    /** @brief  */
    virtual void sendControls(const Controls &controls) noexcept = 0;

    /** @brief  */
    virtual void sendSync(const Tempo &tempo) noexcept = 0;
    /** @brief  */
    virtual void receiveSync(Tempo &tempo) noexcept = 0;

    /** @brief  */
    virtual void onAudioGenerationStarted(void) noexcept = 0;
    virtual void onAudioGenerationStopped(void) noexcept = 0;
    virtual void onAudioBlockGenerated(void) noexcept = 0;

    /** @brief Various flags helpers */
    [[nodiscard]] inline bool hasAudioInput(void) const noexcept    { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::AudioInput); }
    [[nodiscard]] inline bool hasAudioOutput(void) const noexcept   { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::AudioOutput); }
    [[nodiscard]] inline bool hasNoteInput(void) const noexcept     { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::NoteInput); }
    [[nodiscard]] inline bool hasNoteOutput(void) const noexcept    { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::NoteOutput); }
    [[nodiscard]] inline bool hasControlInput(void) const noexcept  { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::ControlInput); }
    [[nodiscard]] inline bool hasSyncInput(void) const noexcept     { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::SyncInput); }
    [[nodiscard]] inline bool hasSyncOutput(void) const noexcept    { return static_cast<std::size_t>(getFlags()) & static_cast<std::size_t>(Flags::SyncOutput); }

};
