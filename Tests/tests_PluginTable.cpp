/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Instance class
 */

#include <gtest/gtest.h>

#include <MLAudio/PluginTable.hpp>

using namespace Audio;

TEST(PluginTable, Instantiation)
{
    auto table = PluginTable::Get();

    EXPECT_NE(table, nullptr);
}