/**
 * @ Author: Pierre Veysseyre
 * @ Description: EnveloppeGenerator implementation
 */

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::ADSR>::processSample(const SampleRate sampleRate) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::ADSR>::processBlock(const SampleRate sampleRate, const BlockSize size) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AR>::processSample(const SampleRate sampleRate) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AR>::processBlock(const SampleRate sampleRate, const BlockSize size) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AD>::processSample(const SampleRate sampleRate) noexcept
{
    const float realMax = static_cast<float>(_max) / 0xFFFF;
    const auto dt = _index / _attack;

    _index += (1 / sampleRate);
    return (dt < 1 ? (dt * realMax) : (dt - 1) * realMax);
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AD>::processBlock(const SampleRate sampleRate, const BlockSize size) noexcept
{
    const float realMax = static_cast<float>(_max) / 0xFFFF;
    const auto dtBegin = _index / _attack;
    const auto dtEnd = (_index + static_cast<float>(size) / sampleRate) / _attack;

    _index += (size / sampleRate);
    if (dtBegin < 1) {
        // Attack stage
        if (dtEnd < 1)
            return (dtEnd - dtBegin) * realMax;
        // Block is between attack & decay
        else
            return realMax;
    }
    // Decay stage
    return (dtEnd - dtBegin - 1) * realMax;
}
