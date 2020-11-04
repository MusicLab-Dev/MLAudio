/**
 * @ Author: Pierre Veysseyre
 * @ Description: PluginTable.cpp
 */

#include "PluginTable.hpp"

Audio::PluginTable *Audio::PluginTable::_Instance { new Audio::PluginTable() };

Audio::PluginTable *Audio::PluginTable::Get(void) noexcept
{
    return _Instance;
}

void Audio::PluginTable::Set(PluginTable *pluginTable) noexcept
{
    if (pluginTable) {
        _Instance = pluginTable;
    }
}
