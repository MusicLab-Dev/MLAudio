project(MLAudio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")

get_filename_component(MLAudioDir ${CMAKE_CURRENT_LIST_FILE} PATH)

include(${MLAudioDir}/DSP/DSPLib.cmake)
include(${MLAudioDir}/MLAudio/MLAudioLib.cmake)

if (${ML_TESTS})
    include(${MLAudioDir}/Tests/MLAudioTests.cmake)
endif ()

if (${ML_BENCHMARKS})
    include(${MLAudioDir}/Benchmarks/MLAudioBenchmarks.cmake)
endif ()