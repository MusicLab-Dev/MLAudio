project(MLAudioTests)

set(MLAudioTestsDir ${MLAudioDir}/Tests)

set(MLAudioTestsSources
    ${MLAudioTestsDir}/tests_Device.cpp
    ${MLAudioTestsDir}/tests_Control.cpp
    ${MLAudioTestsDir}/tests_PluginTable.cpp
    ${MLAudioTestsDir}/tests_Project.cpp
    ${MLAudioTestsDir}/tests_Partition.cpp
    ${MLAudioTestsDir}/tests_Note.cpp
    ${MLAudioTestsDir}/tests_UtilsMidi.cpp
    ${MLAudioTestsDir}/tests_Biquad.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${MLAudioTestsSources})

add_test(NAME ${CMAKE_PROJECT_NAME} COMMAND ${CMAKE_PROJECT_NAME})

target_link_libraries(${CMAKE_PROJECT_NAME}
PUBLIC
    MLAudioLib
    GTest::GTest GTest::Main
)