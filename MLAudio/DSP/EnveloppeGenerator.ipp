/**
 * @ Author: Pierre Veysseyre
 * @ Description: EnveloppeGenerator implementation
 */

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::ADSR>::process(const SampleRate sampleRate) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::ADSR>::process(const SampleRate sampleRate, const BlockSize size) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AR>::process(const SampleRate sampleRate) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AR>::process(const SampleRate sampleRate, const BlockSize size) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AD>::process(const SampleRate sampleRate) noexcept
{
    return 1.0;
}

inline float Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AD>::process(const SampleRate sampleRate, const BlockSize size) noexcept
{
    return 1.0;
}
