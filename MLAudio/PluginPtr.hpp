/**
 * @ Author: Pierre Veysseyre
 * @ Description: PluginPtr
 */

#pragma once

#include "IPlugin.hpp"

namespace Audio
{
    class PluginPtr;
};

/** @brief Store IPlugin shared ownership */
class Audio::PluginPtr
{
public:
    /** @brief Acquire a new plugin, register it and increment ref count */
    PluginPtr(IPlugin * const plugin) noexcept;

    /** @brief Acquire an existing plugin and increment ref count */
    PluginPtr(const PluginPtr &other) noexcept;

    /** @brief Move constructor */
    PluginPtr(PluginPtr &&other) noexcept { swap(other); }

    /** @brief Decrement ref count */
    ~PluginPtr(void) noexcept;

    /** @brief Acquire an existing plugin */
    PluginPtr &operator=(const PluginPtr &other) noexcept;

    /** @brief Move an existing plugin */
    PluginPtr &operator=(PluginPtr &&other) noexcept { swap(other); return *this; }

    /** @brief Swap two instances */
    void swap(PluginPtr &other) noexcept { std::swap(_plugin, other._plugin); }


    /** @brief Dereference plugin pointer */
    [[nodiscard]] IPlugin *operator->(void) noexcept { return _plugin; }
    [[nodiscard]] const IPlugin *operator->(void) const noexcept { return _plugin; }

    /** @brief Get the plugin pointer */
    [[nodiscard]] IPlugin *get(void) noexcept { return _plugin; }
    [[nodiscard]] const IPlugin *get(void) const noexcept { return _plugin; }

private:
    IPlugin *_plugin { nullptr };
};