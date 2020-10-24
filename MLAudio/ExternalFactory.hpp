/**
 * @ Author: Pierre Veysseyre
 * @ Description: ExternalFactory.hpp
 */

#pragma once

#include "IPluginFactory.hpp"

namespace Audio
{
    class ExternalFactory;
};


// Replace Runtime by the 'real' one !
class Runtime
{
private:
    char *_ptr[2];
};

class alignas(64) Audio::ExternalFactory final : public Audio::IPluginFactory
{
public:
    virtual std::string_view getName(void) noexcept final { return _name; }

    virtual std::string_view getPath(void) noexcept final { return _vendor; }

    virtual Tags getTags(void) noexcept final { return _tags; }

    // virtual Capabilities getCapabilities(void) noexcept final;

    virtual SDK getSDK(void) noexcept final;

    virtual PluginPtr instantiate(void) noexcept final;


private:
    FlatString              _name {};
    FlatString              _vendor {};
    Runtime                 _runtime {};
    IPluginFactory::Tags    _tags {};
    char                    __pad[20] {};
};

static_assert(alignof(Audio::ExternalFactory) == 64, "ExternalFactory must be aligned to 64 bytes !");
static_assert(sizeof(Audio::ExternalFactory) == 64, "ExternalFactory must take 64 bytes !");
