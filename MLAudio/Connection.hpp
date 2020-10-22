/*
 * @ Author: Pierre Veysseyre
 * @ Description: Connection
 */

#pragma once

#include <cstdint>
#include <vector>

#include "PluginPtr.hpp"

namespace Audio
{
    class Connection;

    // Replace std::vector by FlatVector
    using Connections = std::vector<Connection>;
};

class alignas(16) Audio::Connection
{
public:
    enum class Type : uint32_t {
        Audio, Midi
    };

private:
    PluginPtr   _plugin { nullptr };
    Type        _type { Type::Audio };
};

static_assert(alignof(Audio::Connection) == 16, "Connection must be aligned to 16 bytes !");
static_assert(sizeof(Audio::Connection) == 16, "Connection must take 16 bytes !");