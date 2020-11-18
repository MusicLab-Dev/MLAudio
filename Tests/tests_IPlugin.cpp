/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of IPlugin class
 */

#include <gtest/gtest.h>

#include <MLAudio/Plugins/SimpleDelay.hpp>

using namespace Audio;

static constexpr auto BlockSize = 1024u;
static constexpr auto ChannelNumber = 2u;

TEST(IPlugin, SimpleDelay)
{
    SimpleDelay delay (BlockSize, ChannelNumber, 10);

    EXPECT_EQ(delay.delay(), 1);
    EXPECT_EQ(delay.readIdx(), 0);
    EXPECT_EQ(delay.writeIdx(), 0);

    delay.onAudioBlockGenerated();
    EXPECT_EQ(delay.readIdx(), 1);
    EXPECT_EQ(delay.writeIdx(), 0);

    // const auto input = BufferViews(ChannelNumber, BlockSize);

    // delay.receiveAudio(input);
    // EXPECT_EQ(delay.readIdx(), 1);
    // EXPECT_EQ(delay.writeIdx(), 1);
}