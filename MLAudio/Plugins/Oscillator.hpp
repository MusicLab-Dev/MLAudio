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

    virtual Flags getFlags(void) const noexcept;

    virtual bool receiveAudio(const Buffers &outputs) noexcept { return false; }
    virtual void sendAudio(Buffers &inputs) noexcept {}

    virtual bool receiveNotes(const Notes &notes) noexcept { return false; }
    virtual void sendNotes(Notes &notes) noexcept {}

    virtual bool receiveControls(const Controls &controls) noexcept { return false; }
    virtual bool sendControls(Controls &controls) noexcept { return false; }

    virtual bool receiveSync(const Tempo &tempo) noexcept { return false; }
    virtual void sendSync(Tempo &tempo) noexcept {}

    virtual void onAudioGenerationStarted(const TimeRange &range) noexcept {}
    virtual void onAudioGenerationStopped(void) noexcept {}
    virtual void onAudioBlockGenerated(void) noexcept {}

private:
    int a { 23 };
};

#include "Oscillator.ipp"
