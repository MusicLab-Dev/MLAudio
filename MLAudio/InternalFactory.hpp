/**
 * @ Author: Pierre Veysseyre
 * @ Description: InternalFactory.hpp
 */

#pragma once

#include "IPluginFactory.hpp"

namespace Audio
{
    template<typename Plugin>
    class InternalFactory;
};

template<typename Plugin>
class Audio::InternalFactory final : public Audio::IPluginFactory
{
public:

    virtual std::string_view getName(void) noexcept final { return _name; }

    virtual std::string_view getPath(void) noexcept final { return _vendor; }

    virtual Tags getTags(void) noexcept final { return _tags; }

    // virtual Capabilities getCapabilities(void) noexcept final;

    virtual SDK getSDK(void) noexcept final;

    virtual PluginPtr instantiate(void) noexcept final;

private:
};