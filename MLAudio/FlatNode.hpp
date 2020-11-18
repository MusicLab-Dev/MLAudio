/**
 * @ Author: Pierre Veysseyre
 * @ Description: FlatNode.hpp
 */

#pragma once

#include "Node.hpp"

namespace Audio
{
    struct FlatNode;

    using FlatTree = Core::FlatVector<FlatNode>;
};

struct alignas_quarter_cacheline Audio::FlatNode
{
    enum class Type : std::uint32_t {
        Audio   = 1,
        Midi    = 1 << 1,
        Control = 1 << 2
    };

    Node   *node { nullptr };
    Type    type { Type::Audio };
};

static_assert_fit_quarter_cacheline(Audio::FlatNode);
