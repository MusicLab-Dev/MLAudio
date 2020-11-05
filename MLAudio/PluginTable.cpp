/**
 * @ Author: Pierre Veysseyre
 * @ Description: PluginTable.cpp
 */

#include <stdexcept>

#include <MLCore/Assert.hpp>

#include "PluginTable.hpp"

Audio::PluginPtr Audio::PluginTable::instantiate(const std::string_view &view)
{
    for (auto &factory : _factories) {
        if (factory->getName() != view)
            continue;
        return instantiate(*factory);
    }
    throw std::logic_error("Audio::PluginTable::instantiate: Plugin '" + std::string(view) + "' not found");
}

void Audio::PluginTable::addPlugin(IPlugin *plugin) noexcept_ndebug
{
    _instances.push(plugin);
    _counters.push(1ul);
}

void Audio::PluginTable::incrementRefCount(IPlugin *plugin) noexcept_ndebug
{
    auto i = 0u;
    for (auto &instance : _instances) {
        if (plugin != instance) {
            ++i;
            continue;
        }
        ++_counters[i];
    }
}

void Audio::PluginTable::decrementRefCount(IPlugin *plugin) noexcept_ndebug
{
    auto i = 0u;
    for (auto &instance : _instances) {
        if (plugin != instance) {
            ++i;
            continue;
        }
        if (!--_counters[i]) {
            delete _instances.at(i);
            _instances.erase(_instances.begin() + i);
            _counters.erase(_counters.begin() + i);
        }
    }
}