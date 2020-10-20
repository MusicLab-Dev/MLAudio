/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: Control.hpp
 */

#pragma once

#include "Automation.hpp"

#include <vector>

namespace ML::Audio
{
    class Control;

    // Replace std::vector by FlatVector
    using Controls = std::vector<Control>;
};

class ML::Audio::Control
{
public:
    Control(void) = default;


    /**
     * @brief Check if the control is muted (not active) or not
     *
     * @return true Control is muted
     * @return false Control isn't muted
     */
    bool muted(void) const noexcept { return _muted; }

    /**
     * @brief Set the muted state of the control
     *
     * @param muted New muted state
     */
    void setMuted(bool muted) noexcept { _muted = muted; }


    /**
     * @brief Get the paramID associated to this control
     *
     * @return ParamID ParamID value
     */
    ParamID paramID(void) const noexcept { return _paramID; }

    /**
     * @brief Set a new ParamID to this control
     *
     * @param paramID New ParamID value
     * @return true New paramID set correctly
     * @return false Invalid paramID, internal paramID hadn't change
     */
    bool setParamID(const ParamID paramID) /* noexcept */ { return false; }


    /**
     * @brief Get the list of Point associated to this control
     *
     * @return Points& Reference to the points
     */
    Points &points(void) noexcept { }

    /**
     * @brief Get the list of Point associated to this control
     *
     * @return Points& Constant reference to the points
     */
    const Points &points(void) const noexcept {}


private:
    Point           _manualPoint {};
    ParamID         _paramID {};
    bool            _manualMode { false };
    bool            _muted { false };
    char            __padding[2] {};
    Automations     _automations { 0u };
};

static_assert(sizeof(ML::Audio::Control) == 32, "Control must take 32 bytes !");
