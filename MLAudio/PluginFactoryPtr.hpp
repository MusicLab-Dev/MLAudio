/**
 * @ Author: Pierre Veysseyre
 * @ Description: PluginFactoryPtr.hpp
 */

#pragma once

#include <memory>

#include "Base.hpp"

namespace Audio
{
    class IPluginFactory;

    using PluginFactoryPtr = std::unique_ptr<IPluginFactory>;

    using PluginFactories = FlatVector<PluginFactoryPtr>;
};
