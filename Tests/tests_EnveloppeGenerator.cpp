/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Enveloppe Generator class
 */

#include <gtest/gtest.h>

#include <MLAudio/EnveloppeGenerator.hpp>

using namespace Audio;
using namespace DSP;

static constexpr SampleRate SR = 48000u;
static constexpr BlockSize Size = 1024u;
static constexpr auto ChannelNumber = 2u;

TEST(EnveloppeGenerator, Initialization)
{
    // EnveloppeGenerator adsr;

}