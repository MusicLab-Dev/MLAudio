project(MLAudio)

get_filename_component(MLAudioDir ${CMAKE_CURRENT_LIST_FILE} PATH)

include(${MLAudioDir}/MLAudio/MLAudioLib.cmake)

if (${ML_TESTS})
    include(${MLAudioDir}/Tests/MLAudioTests.cmake)
endif ()

if (${ML_BENCHMARKS})
    include(${MLAudioDir}/Benchmarks/MLAudioBenchmarks.cmake)
endif ()