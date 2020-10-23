/*
 * @ Author: Pierre Veysseyre
 * @ Description: PluginTable
 */

#pragma once

#include "IPluginFactory.hpp"

namespace Audio
{
    class PluginTable;
};

class Audio::PluginTable
{
public:
    // PluginTable(const PluginTable &) = delete;
    // PluginTable(PluginTable &&) = delete;
    // PluginTable &operator=(const PluginTable &) = delete;
    // PluginTable &operator=(PluginTable &&) = delete;

    static PluginTable *Get(void) noexcept { if (!_Instance) _Instance = new PluginTable(); return _Instance; }
    static void Set(PluginTable *pluginTable) noexcept { if (pluginTable) _Instance = pluginTable; }


    // IPluginFactory &record(const std::string &path);
    // template<typename Type, CustomString Name, IPluginFactory::Tags Tags>
    // IDeviceFactory &record(void);

    /** @brief Get a reference of the plugin factories associated to the table */
    PluginFactories &factories(void) noexcept { return _factories; }

    /** @brief Get a constant reference to the plugin factories associated to the table */
    const PluginFactories &factories(void) const noexcept { return _factories; }

private:
    PluginFactories     _factories { 0u };
    PluginPtrs          _instances { 0u };
    // RefCounts           _counters { 0u };

    static PluginTable *_Instance;


    void addDevice(PluginPtr device);
    void incrementRefCount(PluginPtr device);
    void decrementRefCount(PluginPtr device);
};