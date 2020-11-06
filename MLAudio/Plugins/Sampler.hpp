/**
 * @ Author: Pierre Veysseyre
 * @ Description: Sampler
 */

#pragma once

#include "IPlugin.hpp"

namespace Audio
{
    class Sampler;
};

class Audio::Sampler final : public Audio::IPlugin
{
public:
    Sampler(void) = default;

    virtual bool hasAudioInput(void) const noexcept { return false; }
    virtual bool hasAudioOutput(void) const noexcept { return true; }
    virtual bool receiveAudio(const Buffers &outputs);
    // virtual void sendAudio(Buffers &inputs) = 0;

    virtual bool hasNoteInput(void) const noexcept { return true; }
    virtual bool hasNoteOutput(void) const noexcept { return false; }
    // virtual bool receiveNotes(const Notes &notes) = 0;
    virtual void sendNotes(Notes &notes);

    virtual bool hasControlInput(void) const noexcept { return true; }
    virtual bool hasControlOutput(void) const noexcept { return false; }
    // virtual bool receiveControls(const Controls &controls) = 0;
    virtual bool sendControls(Controls &controls);

    virtual bool hasSyncInput(void) const noexcept { return false; }
    virtual bool hasSyncOutput(void) const noexcept { return false; }
    // virtual bool receiveSync(const Tempo &tempo) = 0;
    // virtual void sendSync(Tempo &tempo) = 0;

    virtual void onAudioGenerationStarted(const TimeRange &range) = 0;
    virtual void onAudioGenerationStopped(void) = 0;
    virtual void onAudioBlockGenerated(void) = 0;


private:
};