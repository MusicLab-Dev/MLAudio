/**
 * @ Author: Pierre Veysseyre
 * @ Description: Project.hpp
 */

#pragma once

#include "FlatNode.hpp"

namespace Audio
{
    class Project;

    using ProjectPtr = Project *;

    using ProjectNameStr = std::unique_ptr<char *>;
};

class Audio::Project
{
public:
    /** @brief PlaybackMode describe project purpose
     * Production is used when the user want to create art !
     * Live is used when the user want to share its art :)
     */
    enum class PlaybackMode : std::uint32_t {
        Production, Live
    };

    Project(ProjectNameStr &&name, PlaybackMode mode)
        : _name(std::move(name)), _playbackMode(mode) {}

    /** @brief  */
    void invalidateFlatTree(void);

    /** @brief  */
    void generateAudioBlock(void);

    /** @brief  */
    void onAudioGenerationStarted(const BeatRange &range);

    /** @brief  */
    void onAudioGenerationStopped(void);

    /** @brief  */
    void onAudioBlockGenerated(void);

private:
    NodePtr         _master { nullptr };
    PlaybackMode    _playbackMode { PlaybackMode::Production };
    FlatTree        _flatTree { 0u };
    ProjectNameStr  _name { nullptr };

    /** @brief  */
    void computeFlatTree(void);
};

// static_assert(alignof(Audio::Project) == 32, "Project must be aligned to 32 bytes !");
static_assert(sizeof(Audio::Project) == 32, "Project must take 32 bytes !");
