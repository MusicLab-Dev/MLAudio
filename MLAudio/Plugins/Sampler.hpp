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

    virtual Flags getFlags(void) const noexcept;

    virtual bool receiveAudio(const Buffers &outputs) noexcept { return false; }
    // virtual void sendAudio(Buffers &inputs) noexcept = 0;

    // virtual bool receiveNotes(const Notes &notes) noexcept = 0;
    virtual void sendNotes(Notes &notes) noexcept { }

    // virtual bool receiveControls(const Controls &controls) noexcept = 0;
    virtual bool sendControls(Controls &controls) noexcept { return false; }

    // virtual bool receiveSync(const Tempo &tempo) noexcept = 0;
    // virtual void sendSync(Tempo &tempo) noexcept = 0;

    virtual void onAudioGenerationStarted(const TimeRange &range) noexcept = 0;
    virtual void onAudioGenerationStopped(void) noexcept = 0;
    virtual void onAudioBlockGenerated(void) noexcept = 0;


private:
};

#include "Sampler.ipp"
