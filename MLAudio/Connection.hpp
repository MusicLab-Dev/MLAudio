/*
 * @ Author: Pierre Veysseyre
 * @ Description: Connection
 */

#pragma once

#include "PluginPtr.hpp"

namespace Audio
{
    class Connection;
};

/** @brief A node connection */
class alignas_quarter_cacheline Audio::Connection
{
public:
    /** @brief Connection type */
    enum class Type : uint32_t {
        Audio, Midi
    };

private:
    PluginPtr   _plugin { nullptr };
    Type        _type { Type::Audio };
};

static_assert_fit_quarter_cacheline(Audio::Connection);
