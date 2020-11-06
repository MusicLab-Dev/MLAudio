/**
 * @ Author: Pierre Veysseyre
 * @ Description: PluginTable template implementation
 */

#include "InternalFactory.hpp"

template<typename Type, const char *Name, Audio::IPluginFactory::Tags FactoryTags>
Audio::IPluginFactory &Audio::PluginTable::registerFactory(void)
{
    _factories.push(std::make_unique<Audio::InternalFactory<Type, Name, FactoryTags>>());
    return *_factories.at(_factories.size() - 1);
}
