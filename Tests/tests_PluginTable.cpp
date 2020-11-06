/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Instance class
 */

#include <gtest/gtest.h>

#include <MLAudio/Plugins/Oscillator.hpp>
#include <MLAudio/PluginTable.hpp>
#include <MLAudio/InternalFactory.hpp>

using namespace Audio;

TEST(PluginTable, Instantiation)
{
    PluginTable::Init();
    {
        auto &table = PluginTable::Get();
        // auto builtinsFactory =

        auto name = Core::FlatString("osc");
        static const char n1[] { "osc" };

        table.registerFactory<Oscillator, n1, IPluginFactory::Tags::Synth>();
        auto p = table.instantiate(n1);
        // table.registerFactory<Oscillator, "osc", IPluginFactory::Tags::Synth>();
    }
    // EXPECT_NE(table, nullptr);
    PluginTable::Destroy();
}