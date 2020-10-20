/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: Automation.hpp
 */

#pragma once

#include "Globals.hpp"

#include <vector>

namespace ML::Audio
{
    class Automation;
    struct Point;

    // Replace std::vector by FlatVector
    using Automations = std::vector<Automation>;
    // Replace std::vector by SortedFlatVector
    using Points = std::vector<Point>;
};

struct ML::Audio::Point {
    enum class CurveType : char {
        Linear, Fast, Slow
    };

    Beat        beat {};
    CurveType   type { CurveType::Linear };
    char        _padding[1] {};
    int16_t     curveRate {};
    ParamValue  value {};
};

class ML::Audio::Automation
{
public:
    // Forward definition to either BeatRange or TimeRange (e.g. Software audio architechture)
    using InstanceType = BeatRange;

    /**
     * @brief Get the automation points
     *
     * @return Points& Reference to points
     */
    Points &points(void) noexcept { return _points; }

    /**
     * @brief Get the automation points
     *
     * @return Points& Constant reference to points
     */
    const Points &points(void) const noexcept { return _points; }


    /**
     * @brief Get the automation instances
     *
     * @return InstanceType& Reference to instances
     */
    InstanceType &instances(void) noexcept { return _instances; }

    /**
     * @brief Get the automation instances
     *
     * @return InstanceType& Reference to instances
     */
    const InstanceType &instances(void) const noexcept { return _instances; }


    /**
     * @brief Check if the automation is muted (not active) or not
     *
     * @return true Automation is muted
     * @return false Automation isn't muted
     */
    bool muted(void) const noexcept { return _muted; }

    /**
     * @brief Set the muted state of the automation
     *
     * @param muted New muted state
     */
    void setMuted(bool muted) noexcept { _muted = muted; }


private:
    Points          _points { 0 };
    InstanceType    _instances {};
    bool            _muted { false };
    char            __padding[7] {};
};

static_assert(sizeof(ML::Audio::Point) == 16, "Point must take 16 bytes !");
static_assert(sizeof(ML::Audio::Automation) == 16, "Automation must take 16 bytes !");