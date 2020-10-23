/**
 * @ Author: Pierre Veysseyre
 * @ Description: FlatNode.hpp
 */

#pragma once

#include "Node.hpp"

namespace Audio
{
    struct FlatNode;

    using FlatTree = FlatVector<FlatNode>;
};

struct alignas(16) Audio::FlatNode
{
    enum class Type : std::uint32_t {
        Audio   = 1,
        Midi    = 1 << 1,
        Control = 1 << 2
    };

    Node   *node { nullptr };
    Type    type { Type::Audio };
};

static_assert(alignof(Audio::FlatNode) == 16, "FlatNode must be aligned to 16 bytes !");
static_assert(sizeof(Audio::FlatNode) == 16, "FlatNode must take 16 bytes !");