/**
 * @ Author: Pierre Veysseyre
 * @ Description: EnveloppeGenerator
 */

#pragma once

#include <MLCore/Utils.hpp>

#include "../BaseDevice.hpp"

#include <iostream>

namespace Audio::DSP
{
    enum class GeneratorType : std::uint8_t {
        ADSR, /*DADSR, DAHDSR,*/ AR, AD
    };

    namespace Internal
    {
        class EnveloppeGeneratorBase;
    };

    template<GeneratorType Generator>
    class EnveloppeGenerator;
};

class Audio::DSP::Internal::EnveloppeGeneratorBase
{
public:

    /** @brief Default constructor */
    EnveloppeGeneratorBase(void) = default;

    /** @brief Trigger the enveloppe */
    void triggerOn(void) noexcept { _index = 0u; }

    /** @brief Stop the enveloppe */
    void triggerOff(void) noexcept { std::cout << "Base\n"; }


protected:
    float           _index  { 0.0 };
};


template<>
class /*alignas_half_cacheline*/ Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::ADSR>
    : DSP::Internal::EnveloppeGeneratorBase
{
public:
    /** @brief Default constructor */
    EnveloppeGenerator(void) = default;

    /** @brief Construct a basic ADSR enveloppe */
    EnveloppeGenerator(const float attack, const float decay, const float sustain, const float release) noexcept
        : _sustain(sustain), _attack(attack), _decay(decay), _release(release) {}


    void triggerOff(void) noexcept { std::cout << "ADSR\n"; }

    /** @brief Compute a singe sample */
    [[nodiscard]] float processSample(const SampleRate sampleRate) noexcept;

    /** @brief Compute a size samples and take the average value inside the block */
    [[nodiscard]] float processBlock(const SampleRate sampleRate, const BlockSize size) noexcept;

private:
    std::uint16_t   _sustain    { 0xFFFF }; // [0:65535]
    float           _attack     { 0.1 };    // In seconds
    float           _decay      { 0.1 };    // In seconds
    float           _release    { 0.01 };   // In seconds
};

// static_assert_fit_half_cacheline(Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::ADSR>);



template<>
class /*alignas_quarter_cacheline*/ Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AR>
    : DSP::Internal::EnveloppeGeneratorBase
{
public:
    /** @brief Default constructor */
    EnveloppeGenerator(void) = default;

    /** @brief Construct a basic AR enveloppe */
    EnveloppeGenerator(const float attack, const float release) noexcept
        : _attack(attack), _release(release) {}


    void triggerOff(void) noexcept { std::cout << "AR\n"; }

    /** @brief Compute a singe sample */
    [[nodiscard]] float processSample(const SampleRate sampleRate) noexcept;

    /** @brief Compute a size samples and take the average value inside the block */
    [[nodiscard]] float processBlock(const SampleRate sampleRate, const BlockSize size) noexcept;

private:
    float   _attack     { 0.1 };    // In seconds
    float   _release    { 0.01 };   // In seconds
};

// static_assert_fit_quarter_cacheline(Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AR>);


template<>
class alignas_quarter_cacheline Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AD>
    : private DSP::Internal::EnveloppeGeneratorBase
{
public:
    /** @brief Default constructor */
    EnveloppeGenerator(void) = default;

    /** @brief Construct a basic AD enveloppe */
    EnveloppeGenerator(const float attack, const float decay) noexcept
        : _attack(attack), _decay(decay) {}


    void triggerOff(void) noexcept { std::cout << "AD\n"; }

    /** @brief Compute a singe sample */
    [[nodiscard]] float processSample(const SampleRate sampleRate) noexcept;

    /** @brief Compute a size samples and take the average value inside the block */
    [[nodiscard]] float processBlock(const SampleRate sampleRate, const BlockSize size) noexcept;

private:
    std::uint16_t   _max    { 0xFFFF }; // [0:65535]
    float           _attack { 0.1 };    // In seconds
    float           _decay  { 0.1 };    // In seconds
};

static_assert_fit_quarter_cacheline(Audio::DSP::EnveloppeGenerator<Audio::DSP::GeneratorType::AD>);


#include "EnveloppeGenerator.ipp"