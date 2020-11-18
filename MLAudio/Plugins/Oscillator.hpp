/**
 * @ Author: Pierre Veysseyre
 * @ Description: Oscillator
 */

#pragma once

#include "../IPlugin.hpp"
// #include "../NoteManager.hpp"

namespace Audio
{
    class Oscillator;
};

class Audio::Oscillator final : public Audio::IPlugin
{
public:

    virtual Flags getFlags(void) const noexcept;

    virtual void sendAudio(const BufferViews &inputs) noexcept;
    virtual void receiveAudio(BufferView output) noexcept;

    virtual void sendNotes(const Notes &notes) noexcept;
    virtual void receiveNotes(Notes &notes) noexcept;

    virtual void sendControls(const Controls &controls) noexcept;

    virtual void sendSync(const Tempo &tempo) noexcept {}
    virtual void receiveSync(Tempo &tempo) noexcept {}

    virtual void onAudioGenerationStarted(void) noexcept {}
    virtual void onAudioGenerationStopped(void) noexcept {}
    virtual void onAudioBlockGenerated(void) noexcept {}

private:
    // NoteManager     _noteManager;
};

// static_assert_fit_half_cacheline(Audio::Oscillator);

#include "Oscillator.ipp"
