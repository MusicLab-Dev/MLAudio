/*
 * @ Author: Pierre Veysseyre
 * @ Description: Control.hpp
 */

#pragma once

#include <bitset>

#include "Automation.hpp"

namespace Audio
{
    class Control;

    using Controls = FlatVector<Control>;
};

/** @brief A control describe how to change a plugin parameter over time (both Production & Live).
 * It contains a set of 16 automations. */
class alignas(32) Audio::Control
{
public:
    Control(const ParamID paramID) : _paramID(paramID) {}

    /** @brief Check if the control is muted (not active) or not */
    [[nodiscard]] bool muted(void) const noexcept { return _muted; }

    /** @brief Set the muted state of the control */
    void setMuted(bool muted) noexcept { _muted = muted; }


    /** @brief Get the the whole automation muted states */
    [[nodiscard]] std::uint16_t automationMutedState(void) const noexcept { return _automationMutedStates; }

    /** @brief Check if an automation is muted */
    [[nodiscard]] bool isAutomationMuted(const std::size_t index) const noexcept { return (_automationMutedStates & (1u << index)) > 0; }

    /** @brief Check if an automation is muted */
    bool setAutomationMutedState(const std::size_t index, const bool state) noexcept;

    /** @brief Check if the automation set if full */
    [[nodiscard]] bool isAutomationsFull(void) const noexcept;

    /** @brief Get the paramID associated to this control */
    [[nodiscard]] ParamID paramID(void) const noexcept { return _paramID; }

    /** @brief Set a new ParamID to this control, returns true if the id changed */
    bool setParamID(const ParamID paramID) noexcept;


    /** @brief Get the list of Point associated to this control */
    [[nodiscard]] Points &points(void) noexcept;

    /** @brief Get the list of Point associated to this control */
    [[nodiscard]] const Points &points(void) const noexcept;

private:
    Point           _manualPoint {};
    ParamID         _paramID {};
    std::uint16_t   _automationMutedStates {};
    bool            _manualMode { false };
    bool            _muted { false };
    Automations     _automations { 0u };
};

#include "Control.ipp"

static_assert(alignof(Audio::Control) == 32, "Control must be aligned to 32 bytes !");
static_assert(sizeof(Audio::Control) == 32, "Control must take 32 bytes !");
