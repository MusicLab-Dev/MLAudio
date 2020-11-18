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

static Buffer GetBuffer(void) noexcept { return Buffer(BlockSize * sizeof(T), ChannelArrangement::Stereo); }

TEST(Buffer, Initialization)
{
    Buffer buf(GetBuffer());

    for (auto i = 0u; i < BlockSize; ++i) {
        buf.data<T>(Channel::Left)[i] = i;
        buf.data<T>(Channel::Right)[i] = i;
    }
    for (auto i = 0u; i < BlockSize; ++i) {
        EXPECT_EQ(buf.data<T>(Channel::Left)[i], i);
        EXPECT_EQ(buf.data<T>(Channel::Right)[i], i);
    }
}

TEST(BufferViews, Initialization)
{
    Buffer dummy(GetBuffer());
    BufferViews buf1;
    BufferViews buf2;

    for (auto n = 0u; n < ChannelNumber / 2; ++n) {
        auto b = buf1.push(dummy);
        for (auto i = 0u; i < BlockSize; ++i) {
            b.data<T>(Channel::Left)[i] = i;
            b.data<T>(Channel::Right)[i] = i;
        }
    }

    buf2 = buf1;
    for (auto n = 0u; n < ChannelNumber / 2; ++n) {
        auto b = buf1.push(dummy);
        for (auto i = 0u; i < BlockSize; ++i) {
            EXPECT_EQ(b.data<T>(Channel::Left)[i], i);
            EXPECT_EQ(b.data<T>(Channel::Right)[i], i);
        }
    }
}
