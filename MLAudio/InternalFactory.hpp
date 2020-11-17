/**
 * @ Author: Pierre Veysseyre
 * @ Description: InternalFactory.hpp
 */

#pragma once

#include "IPluginFactory.hpp"

namespace Audio
{
    template<typename Plugin, const char *Name, Audio::IPluginFactory::Tags FactoryTags>
    class InternalFactory;
};

template<typename Plugin, const char *Name, Audio::IPluginFactory::Tags FactoryTags>
class Audio::InternalFactory final : public Audio::IPluginFactory
{
public:

    InternalFactory(void) = default;

    virtual std::string_view getName(void) noexcept final { return std::string_view(Name); }

    std::string_view getVendor(void) noexcept { return "_vendor"; }

    virtual std::string_view getPath(void) noexcept final { return "_path"; }

    virtual Tags getTags(void) noexcept final { return FactoryTags; }

    // virtual Capabilities getCapabilities(void) noexcept final;

    virtual SDK getSDK(void) noexcept final { return SDK::Internal; }

    [[nodiscard]] virtual IPlugin *instantiate(void) noexcept final { return new Plugin(); }

private:
};