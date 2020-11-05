project(MLAudioLib)

get_filename_component(MLAudioLibDir ${CMAKE_CURRENT_LIST_FILE} PATH)

find_package(SDL2 REQUIRED)

set(MLAudioLibSources
    ${MLAudioLibDir}/AScheduler.hpp
    ${MLAudioLibDir}/Automation.hpp
    ${MLAudioLibDir}/Base.hpp
    ${MLAudioLibDir}/Buffer.hpp
    ${MLAudioLibDir}/Connection.hpp
    ${MLAudioLibDir}/Control.hpp
    ${MLAudioLibDir}/Control.ipp
    ${MLAudioLibDir}/Device.hpp
    ${MLAudioLibDir}/Device.cpp
    ${MLAudioLibDir}/Device.ipp
    ${MLAudioLibDir}/ExternalFactory.hpp
    ${MLAudioLibDir}/FlatNode.hpp
    ${MLAudioLibDir}/InternalFactory.hpp
    ${MLAudioLibDir}/IPlugin.hpp
    ${MLAudioLibDir}/IPluginFactory.hpp
    ${MLAudioLibDir}/Node.hpp
    ${MLAudioLibDir}/Node.ipp
    ${MLAudioLibDir}/Note.hpp
    ${MLAudioLibDir}/Partition.hpp
    ${MLAudioLibDir}/Partition.ipp
    ${MLAudioLibDir}/PluginPtr.hpp
    ${MLAudioLibDir}/PluginTable.hpp
    ${MLAudioLibDir}/PluginTable.cpp
    ${MLAudioLibDir}/Project.hpp
    ${MLAudioLibDir}/Project.cpp
    ${MLAudioLibDir}/Biquad.hpp
    ${MLAudioLibDir}/Biquad.cpp
)

add_library(${PROJECT_NAME} ${MLAudioLibSources})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MLAudioDir}
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    MLCoreLib
    ${SDL2_LIBRARIES}
)
