/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: PluginPtr.hpp
 */

#pragma once

#include "IPlugin.hpp"

namespace ML::Audio
{
    class PluginPtr;
};

class ML::Audio::PluginPtr
{
public:
    PluginPtr(IPlugin *plugin);

    IPlugin *get(void);
    const IPlugin *get(void) const;

    void swap(PluginPtr &plugin);

private:
    IPlugin *_plugin { nullptr };
};