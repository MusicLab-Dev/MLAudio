/**
 * @ Author: Pierre Veysseyre
 * @ Description: SimpleDelay
 */

#pragma once

#include "../IPlugin.hpp"

namespace Audio
{
    class SimpleDelay;
};

class alignas_half_cacheline Audio::SimpleDelay : public Audio::IPlugin
{
public:
    using Cache = Core::TinyVector<BufferViews>;
    using Index = std::uint16_t;

    /** @brief Init a simple delay with a fixed max size
     * @param cacheSize In block, use SampleRate / 'SizeInSec'
     */
    SimpleDelay(const std::size_t blockSize, const ChannelArrangement channelArrangement, const std::size_t cacheSize) : _cache(cacheSize) {
        for (auto i = 0u; i < cacheSize; ++i)
            _cache[i].push(Buffer(blockSize, channelArrangement));
    }


    virtual Flags getFlags(void) const noexcept;

    virtual void sendAudio(const BufferViews &inputs) noexcept;
    virtual void receiveAudio(BufferView output) noexcept;

    virtual void sendNotes(const Notes &notes) noexcept {}
    virtual void receiveNotes(Notes &notes) noexcept {}

    virtual void sendControls(const Controls &controls) noexcept {}

    virtual void sendSync(const Tempo &tempo) noexcept {}
    virtual void receiveSync(Tempo &tempo) noexcept {}

    virtual void onAudioGenerationStarted(void) noexcept;
    virtual void onAudioGenerationStopped(void) noexcept;
    virtual void onAudioBlockGenerated(void) noexcept;


    Index readIdx(void) const noexcept { return _readIdx; }
    Index writeIdx(void) const noexcept { return _writeIdx; }

    const float delay(void) const noexcept { return _delay; }
    void setDelay(const float delay) noexcept { _delay = (delay > 1.0 ? 1.0 : (delay < 0.0 ? 0.0 : delay)); }

private:
    Cache   _cache;
    Index   _readIdx { 0u };
    Index   _writeIdx { 0u };

    /** @brief Delay parameter range from 0 to 1
     * If delay == 0, this plugin as no effect
     * If delay == 1, the delay length equals to te cache size
     */
    float   _delay { 1.0 };

    void incrementIdx(Index &index) noexcept;
};

static_assert_fit_half_cacheline(Audio::SimpleDelay);

#include "SimpleDelay.ipp"
