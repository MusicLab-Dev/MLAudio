project(MLAudioBenchmarks)

set(MLAudioBenchmarksDir ${MLAudioDir}/Benchmarks)

set(MLAudioBenchmarksSources
    ${MLAudioBenchmarksDir}/Main.cpp
    ${MLAudioBenchmarksDir}/bench_Instance.cpp
    ${MLAudioBenchmarksDir}/bench_Biquad.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${MLAudioBenchmarksSources})

target_link_libraries(${CMAKE_PROJECT_NAME}
PUBLIC
    MLAudioLib
    benchmark::benchmark
)