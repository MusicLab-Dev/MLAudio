project(MLAudioLib)

get_filename_component(MLAudioLibDir ${CMAKE_CURRENT_LIST_FILE} PATH)

find_package(SDL2 REQUIRED)

set(MLAudioLibSources
    ${MLAudioLibDir}/AScheduler.hpp
    ${MLAudioLibDir}/Automation.hpp
    ${MLAudioLibDir}/Base.hpp
    ${MLAudioLibDir}/BaseDevice.hpp
    ${MLAudioLibDir}/BaseIndex.hpp
    ${MLAudioLibDir}/UtilsMidi.hpp
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
    ${MLAudioLibDir}/Partition.hpp
    ${MLAudioLibDir}/Partition.ipp
    ${MLAudioLibDir}/Note.hpp
    ${MLAudioLibDir}/FlatNote.hpp
    ${MLAudioLibDir}/Note.ipp
    ${MLAudioLibDir}/PluginPtr.hpp
    ${MLAudioLibDir}/PluginTable.hpp
    ${MLAudioLibDir}/PluginTable.cpp
    ${MLAudioLibDir}/PluginTable.ipp
    ${MLAudioLibDir}/Project.hpp
    ${MLAudioLibDir}/Project.cpp

    ${MLAudioLibDir}/Plugins/Managers/NoteManager.hpp
    ${MLAudioLibDir}/Plugins/Managers/NoteManager.ipp

    ${MLAudioLibDir}/Plugins/Oscillator.hpp
    ${MLAudioLibDir}/Plugins/Oscillator.ipp
    ${MLAudioLibDir}/Plugins/SimpleDelay.hpp
    ${MLAudioLibDir}/Plugins/SimpleDelay.ipp
    ${MLAudioLibDir}/Plugins/Sampler.hpp
    ${MLAudioLibDir}/Plugins/Sampler.ipp

    ${MLAudioLibDir}/DSP/Biquad.hpp
    ${MLAudioLibDir}/DSP/Biquad.cpp
    ${MLAudioLibDir}/DSP/Biquad.ipp
    ${MLAudioLibDir}/DSP/EnveloppeGenerator.hpp
    ${MLAudioLibDir}/DSP/EnveloppeGenerator.ipp
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
