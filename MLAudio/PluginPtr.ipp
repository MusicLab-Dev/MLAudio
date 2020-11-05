/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: PluginPtr
 */

inline Audio::PluginPtr::PluginPtr(IPlugin * const plugin) noexcept
    : _plugin(plugin)
{
    PluginTable::Get().addPlugin(plugin);
}

inline Audio::PluginPtr::PluginPtr(const PluginPtr &other) noexcept
    : _plugin(other._plugin)
{
    PluginTable::Get().incrementRefCount(_plugin);
}

inline Audio::PluginPtr::~PluginPtr(void) noexcept
{
    if (_plugin)
        PluginTable::Get().decrementRefCount(_plugin);
}

inline Audio::PluginPtr &Audio::PluginPtr::operator=(const PluginPtr &other) noexcept
{
    PluginTable::Get().incrementRefCount(_plugin);
    return *this;
}
