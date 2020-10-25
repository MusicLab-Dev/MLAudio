project(MLAudioLib)

get_filename_component(MLAudioLibDir ${CMAKE_CURRENT_LIST_FILE} PATH)

set(MLAudioLibSources
    ${MLAudioLibDir}/Instance.hpp
    ${MLAudioLibDir}/Instance.cpp
    ${MLAudioLibDir}/Device.hpp
    ${MLAudioLibDir}/Device.cpp
    ${MLAudioLibDir}/Device.ipp
    ${MLAudioLibDir}/Control.hpp
    ${MLAudioLibDir}/Control.ipp
)

add_library(${PROJECT_NAME} ${MLAudioLibSources})

target_include_directories(${PROJECT_NAME} PUBLIC ${MLAudioDir})

target_link_libraries(${PROJECT_NAME}
PUBLIC
    MLCoreLib
)
