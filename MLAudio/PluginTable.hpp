/*
 * @ Author: Pierre Veysseyre
 * @ Description: PluginTable
 */

#pragma once

#include "IPluginFactory.hpp"
#include "PluginPtr.hpp"

namespace Audio
{
    class PluginTable;
};

class alignas(32) Audio::PluginTable
{
public:

    // PluginTable(const PluginTable &) = delete;
    // PluginTable(PluginTable &&) = delete;
    // PluginTable &operator=(const PluginTable &) = delete;
    // PluginTable &operator=(PluginTable &&) = delete;

    static PluginTable *Get(void) noexcept;

    static void Set(PluginTable *pluginTable) noexcept;

    IPluginFactory &record(const std::string &path);
    template<typename Type, CustomString Name, IPluginFactory::Tags Tags>
    IPluginFactory &record(void);


    /** @brief Get a reference of the plugin factories associated to the table */
    PluginFactories &factories(void) noexcept { return _factories; }

    /** @brief Get a constant reference to the plugin factories associated to the table */
    const PluginFactories &factories(void) const noexcept { return _factories; }

private:
    static PluginTable *_Instance ;

    PluginFactories     _factories { 0u };
    PluginPtrs          _instances { 0u };
    RefCounts           _counters { 0u };

    PluginTable() {}

    void addPlugin(PluginPtr plugin);
    void incrementRefCount(PluginPtr plugin);
    void decrementRefCount(PluginPtr plugin);
};

static_assert(alignof(Audio::PluginTable) == 32, "PluginTable must be aligned to 32 bytes !");
static_assert(sizeof(Audio::PluginTable) == 32, "PluginTable must take 32 bytes !");
