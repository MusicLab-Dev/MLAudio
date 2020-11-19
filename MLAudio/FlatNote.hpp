/**
 * @ Author: Pierre Veysseyre
 * @ Description: FlatNote
 */

#pragma once

#include "Base.hpp"

namespace Audio
{
    struct FlatNote;
};

/** FlatNote don't store the range and the event type */
struct alignas_eighth_cacheline Audio::FlatNote
{
    /** @brief Default constructor */
    FlatNote(void) = default;

    /** @brief Custom constructor */
    FlatNote(const Key key_, const Velocity velocity_, const Tuning tunning_ = 0u)
        : key(key_), velocity(velocity_), tunning(tunning_) {}


    Key         key { 69u };
    Velocity    velocity { 0x7F };
    Tuning      tunning { 0u };
    bool        active { false };
};

static_assert_fit_eighth_cacheline(Audio::FlatNote);
