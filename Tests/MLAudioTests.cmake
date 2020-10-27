project(MLAudioTests)

set(MLAudioTestsDir ${MLAudioDir}/Tests)

set(MLAudioTestsSources
    ${MLAudioTestsDir}/tests_Device.cpp
    ${MLAudioTestsDir}/tests_Control.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${MLAudioTestsSources})

add_test(NAME ${CMAKE_PROJECT_NAME} COMMAND ${CMAKE_PROJECT_NAME})

target_link_libraries(${CMAKE_PROJECT_NAME}
PUBLIC
    MLAudioLib
    GTest::GTest GTest::Main
)