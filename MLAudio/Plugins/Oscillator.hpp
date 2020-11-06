/**
 * @ Author: Pierre Veysseyre
 * @ Description: Oscillator
 */

#pragma once

#include "../IPlugin.hpp"

namespace Audio
{
    class Oscillator;
};

class Audio::Oscillator final : public Audio::IPlugin
{
public:
    Oscillator(void) = default;

    ~Oscillator(void) = default;

    virtual Flags getFlags(void) const noexcept;

    virtual bool hasAudioInput(void) const noexcept { return false; }
    virtual bool hasAudioOutput(void) const noexcept { return true; }
    virtual bool receiveAudio(const Buffers &outputs) {}
    virtual void sendAudio(Buffers &inputs) {}

    virtual bool hasNoteInput(void) const noexcept { return true; }
    virtual bool hasNoteOutput(void) const noexcept { return false; }
    virtual bool receiveNotes(const Notes &notes) {}
    virtual void sendNotes(Notes &notes) {}

    virtual bool hasControlInput(void) const noexcept { return true; }
    virtual bool hasControlOutput(void) const noexcept { return false; }
    virtual bool receiveControls(const Controls &controls) {}
    virtual bool sendControls(Controls &controls) {}

    virtual bool hasSyncInput(void) const noexcept { return false; }
    virtual bool hasSyncOutput(void) const noexcept { return false; }
    virtual bool receiveSync(const Tempo &tempo) {}
    virtual void sendSync(Tempo &tempo) {}

    virtual void onAudioGenerationStarted(const TimeRange &range) {}
    virtual void onAudioGenerationStopped(void) {}
    virtual void onAudioBlockGenerated(void) {}

private:
    int a { 23 };
};

#include "Oscillator.ipp"
