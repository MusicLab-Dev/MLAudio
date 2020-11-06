/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Partition class
 */

#include <gtest/gtest.h>

#include <MLAudio/Partition.hpp>

using namespace Audio;

TEST(Partition, Basics)
{
    auto partition = Partition();

    EXPECT_EQ(partition.channels(), 0u);
    EXPECT_EQ(partition.count(), 0u);
    EXPECT_EQ(partition.instances().size(), 0u);
    EXPECT_EQ(partition.notes().size(), 0u);
}