/*
 * @ Author: Pierre Veysseyre
 * @ Description: PluginTable
 */

#pragma once

#include <MLCore/Assert.hpp>
#include <MLCore/Vector.hpp>

#include "PluginPtr.hpp"

namespace Audio
{
    class PluginTable;

    /** @brief Vector of plugin factories */
    using PluginFactories = Core::TinyVector<PluginFactoryPtr>;

    /** @brief Vector of plugin pointers */
    using Plugins = Core::TinyVector<IPlugin *>;

    /** @brief Vector of reference counters */
    using RefCounts = Core::TinyVector<std::uint32_t>;
};

class alignas(64) Audio::PluginTable
{
public:
    /** @brief Initialize unique instance */
    static void Init(void) { _Instance.reset(new PluginTable()); }

    /** @brief Destroy unique instance */
    static void Destroy(void) { _Instance.reset(); }

    /** @brief Return the unique plugin table instance */
    [[nodiscard]] static PluginTable &Get(void) noexcept { return *_Instance; }


    /** @brief Register a factory using a path */
    IPluginFactory &registerFactory(const std::string &path);

    /** @brief Register a factory using a compiled plugin */
    template<typename Type, const char *Name, IPluginFactory::Tags Tags>
    IPluginFactory &registerFactory(void);


    /** @brief Instantiates a new plugin using its factory name */
    [[nodiscard]] PluginPtr instantiate(const std::string_view &view);

    /** @brief Instantiates a new plugin using its factory */
    [[nodiscard]] PluginPtr instantiate(IPluginFactory &factory) { return PluginPtr(factory.instantiate()); }


    /** @brief Get a reference of the plugin factories associated to the table */
    [[nodiscard]] PluginFactories &factories(void) noexcept { return _factories; }

    /** @brief Get a constant reference to the plugin factories associated to the table */
    [[nodiscard]] const PluginFactories &factories(void) const noexcept { return _factories; }


public: // Functions reserved to internal usage
    /** @brief Register a plugin into the table and icrement its ref count */
    void addPlugin(IPlugin *plugin) noexcept_ndebug;

    /** @brief Increment reference count of a plugin */
    void incrementRefCount(IPlugin *plugin) noexcept_ndebug;

    /** @brief Decrement reference count of a plugin */
    void decrementRefCount(IPlugin *plugin) noexcept_ndebug;

private:
    static inline std::unique_ptr<PluginTable> _Instance {};

    PluginFactories     _factories {};
    Plugins             _instances {};
    RefCounts           _counters {};

    /** @brief Private constructor */
    PluginTable(void) noexcept = default;

    /** @brief Deleted semantics */
    PluginTable(const PluginTable &other) noexcept = delete;
    PluginTable(PluginTable &&other) noexcept = delete;
    PluginTable &operator=(const PluginTable &other) noexcept = delete;
    PluginTable &operator=(PluginTable &&other) noexcept = delete;
};

static_assert(alignof(Audio::PluginTable) == 64, "PluginTable must be aligned to 64 bytes !");
static_assert(sizeof(Audio::PluginTable) == 64, "PluginTable must take 64 bytes !");

#include "PluginPtr.ipp"