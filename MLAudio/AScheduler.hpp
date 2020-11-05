/**
 * @ Author: Pierre Veysseyre
 * @ Description: AScheduler
 */

#pragma once

#include <functional>
#include <atomic>
#include <future>
#include <queue>

#include "Project.hpp"
#include "Buffer.hpp"

namespace Audio
{
    class AScheduler;

    using ApplyFunctor = std::function<void(void)>;
    using NotifyFunctor = std::function<void(void)>;

    // Replace std::queue with SPSCQueue
    using StreamPtr = std::unique_ptr<std::queue<std::byte>>;
};

class Audio::AScheduler
{
public:
    struct Event
    {
        ApplyFunctor    apply { nullptr };
        NotifyFunctor   notify { nullptr };
    };

    using Events = Core::FlatVector<Event>;

    enum class State : std::uint32_t {
        Pause, Play
    };

    void run(void) noexcept;

    void generateBlock(void) noexcept;


    bool play(void) noexcept;

    bool pause(void) noexcept;

    bool stop(void) noexcept;


    Beat currentBeat(void) const noexcept;

    bool setCurrentBeat(const Beat beat) const noexcept;


    Project &project(void) noexcept { return *_project; }

    const Project &project(void) const noexcept { return *_project; }

    void setProject(ProjectPtr &&project) noexcept { _project = std::move(project); }


    void pushEvent(ApplyFunctor &&apply, NotifyFunctor &&notify);

    bool applyEvent(void);

    void notifyEvent(void);


    bool moveBlockToStream(void);

    bool readFromStream(Buffer &buffer);


protected:
    template<typename Functor, typename ...Args>
    std::future<decltype(std::declval<Functor>()(std::declval<Args>()...))>
        postWork(Functor &&functor, Args &&...args) = 0;


    void onAudioBlockGenerated(void) = 0;

private:
    std::atomic<State>      _state { State::Pause };
    char                    __pad[4];
    Events                  _events { 0u };
    BeatRange               _currentBeatRange {};
    ProjectPtr              _project { nullptr };
    StreamPtr               _stream { nullptr };
};


static_assert(sizeof(Audio::AScheduler) == 56, "AScheduler must take 56 bytes !");
