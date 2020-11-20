/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Enveloppe Generator class
 */

#include <gtest/gtest.h>

#include <MLAudio/DSP/EnveloppeGenerator.hpp>

using namespace Audio;

static constexpr BlockSize Size = 1024u;
static constexpr SampleRate SR = 48000u;

using EnvAD =   DSP::EnveloppeGenerator<DSP::GeneratorType::AD>;
using EnvAR =   DSP::EnveloppeGenerator<DSP::GeneratorType::AR>;
using EnvADSR = DSP::EnveloppeGenerator<DSP::GeneratorType::ADSR>;


TEST(EnveloppeGenerator, Simple_AttackDecay)
{
    EnvAD ad;

    ad.triggerOff();

    auto rB = ad.processBlock(SR, Size);
    auto rS = ad.processSample(SR);

    (void)rB;
    (void)rS;
}

TEST(EnveloppeGenerator, Simple_AttackRelease)
{
    EnvAR ar;

}

TEST(EnveloppeGenerator, Simple_AttackDecayReleaseSustain)
{
    EnvADSR adsr;

}