/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Buffer class
 */

#include <gtest/gtest.h>

#include <MLAudio/Buffer.hpp>

using namespace Audio;

static constexpr auto BlockSize = 1024u;
static constexpr auto ChannelNumber = 2u;

using T = int;

TEST(Buffer, Initialization)
{
    // auto buf = Buffer(BlockSize * sizeof(T), ChannelArrangement::Mono);

    // for (auto i = 0u; i < BlockSize; ++i) {
    //     buf.data<T>(Channel::Left)[i] = i;
    //     buf.data<T>(Channel::Right)[i] = i;
    // }
    // for (auto i = 0u; i < BlockSize; ++i) {
    //     EXPECT_EQ(buf.data<T>(Channel::Left)[i], i);
    //     EXPECT_EQ(buf.data<T>(Channel::Right)[i], i);
    // }
}

TEST(BufferViews, Initialization)
{
    // BufferViews buf1(ChannelNumber, BlockSize * sizeof(T));
    // auto buf2 = BufferViews(ChannelNumber, BlockSize * sizeof(T));


    // for (auto n = 0u; n < ChannelNumber; ++n)
    // for (auto i = 0u; i < 2; ++i)
    //     bb[i] = i;

    // buf2 = buf1;
    // for (auto n = 0u; n < BlockSize; ++n)
    // for (auto i = 0u; i < BlockSize; ++i) {
    //     EXPECT_EQ(buf1[n].data<T>()[i], i);
        // EXPECT_EQ(buf2[n].data<T>()[i], i);
    // }
}
