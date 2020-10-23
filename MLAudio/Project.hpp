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
    enum class PlaybackMode : std::uint32_t {
        Production, Live
    };

    void invalidateFlatTree(void);
    void generateAudioBlock(void);
    void onAudioGenerationStarted(const BeatRange &range);
    void onAudioGenerationStopped(void);
    void onAudioBlockGenerated(void);

private:
    NodePtr         _master { nullptr };
    PlaybackMode    _playbackMode { PlaybackMode::Production };
    FlatTree        _flatTree { 0u };
    ProjectNameStr  _name { nullptr };

    void computeFlatTree(void);
};

static_assert(sizeof(Audio::Project) == 32, "Project must take 32 bytes !");
