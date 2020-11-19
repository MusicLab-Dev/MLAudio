/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of IPlugin class
 */

#include <gtest/gtest.h>

#include <MLAudio/Plugins/SimpleDelay.hpp>
#include <MLAudio/Plugins/Oscillator.hpp>

using namespace Audio;

static constexpr BlockSize Size = 1024u;
static constexpr auto Arrangement = ChannelArrangement::Stereo;
static constexpr auto MaxInputs = 4;

using T = int;

static Buffer GetBuffer(void) noexcept {
    Buffer dumb(Size * sizeof(T), Arrangement);
    for (auto c = 0u; c < static_cast<std::uint32_t>(Arrangement); ++c)
    for (auto i = 0u; i < Size; ++i)
        dumb.data<T>(static_cast<Channel>(c))[i] = static_cast<T>(i);
    return dumb;
}

TEST(IPlugin, SimpleDelay)
{
    SimpleDelay delay (Size, Arrangement, 10);

    EXPECT_EQ(delay.delay(), 1);
    EXPECT_EQ(delay.readIdx(), 0);
    EXPECT_EQ(delay.writeIdx(), 0);

    delay.onAudioBlockGenerated();
    EXPECT_EQ(delay.readIdx(), 1);
    EXPECT_EQ(delay.writeIdx(), 0);

    BufferViews input;
    for (auto i = 0u; i < MaxInputs; ++i) {
        auto dum = GetBuffer();
        auto b = input.push(dum);
        for (auto c = 0u; c < static_cast<std::uint32_t>(Arrangement); ++c)
        for (auto j = 0u; j < Size; ++j)
            b.data<T>(static_cast<Channel>(c))[j] = 0;
    }

    delay.sendAudio(input);
    EXPECT_EQ(delay.readIdx(), 1);
    EXPECT_EQ(delay.writeIdx(), 1);

    Buffer dummy = GetBuffer();
    delay.receiveAudio(dummy);
    EXPECT_EQ(delay.readIdx(), 1);
    EXPECT_EQ(delay.writeIdx(), 1);

    delay.onAudioBlockGenerated();
    EXPECT_EQ(delay.readIdx(), 2);
    EXPECT_EQ(delay.writeIdx(), 1);
}

TEST(IPlugin, Oscillator)
{
    // Oscillator osc;
    // auto env = osc.enveloppe();

    // env.triggerOff();

}