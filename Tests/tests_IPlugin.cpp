/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of IPlugin class
 */

#include <gtest/gtest.h>

#include <MLAudio/Plugins/SimpleDelay.hpp>
#include <MLAudio/Plugins/Oscillator.hpp>

using namespace Audio;

static constexpr BlockSize Size = 1024u;
static constexpr auto ChannelNumber = 2u;

TEST(IPlugin, SimpleDelay)
{
    SimpleDelay delay (Size, ChannelNumber, 10);

    EXPECT_EQ(delay.delay(), 1);
    EXPECT_EQ(delay.readIdx(), 0);
    EXPECT_EQ(delay.writeIdx(), 0);

    delay.onAudioBlockGenerated();
    EXPECT_EQ(delay.readIdx(), 1);
    EXPECT_EQ(delay.writeIdx(), 0);

    // const auto input = BufferViews(ChannelNumber, Size);

    // delay.receiveAudio(input);
    // EXPECT_EQ(delay.readIdx(), 1);
    // EXPECT_EQ(delay.writeIdx(), 1);
}

TEST(IPlugin, Oscillator)
{
    // std::cout << "Type: sizeof, alignof\n\n";
    // std::cout << "EnveloppeGenerator<ADSR>: " << sizeof(DSP::EnveloppeGenerator<DSP::GeneratorType::ADSR>) << ", " << alignof(DSP::EnveloppeGenerator<DSP::GeneratorType::ADSR>) << std::endl;
    // std::cout << "NoteManagerPtr: " << sizeof(NoteManagerPtr) << ", " << alignof(NoteManagerPtr) << std::endl;
    // std::cout << "IPlugin: " << sizeof(IPlugin) << ", " << alignof(IPlugin) << std::endl;
    // std::cout << "Oscillator: " << sizeof(Oscillator) << ", " << alignof(Oscillator) << std::endl;
}