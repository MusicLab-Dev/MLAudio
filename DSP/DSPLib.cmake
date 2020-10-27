project(DSPLib)

get_filename_component(DSPLibDir ${CMAKE_CURRENT_LIST_FILE} PATH)

set(DSPLibSources
    ${DSPLibDir}/Biquad.hpp
    ${DSPLibDir}/Biquad.cpp
)

add_library(${PROJECT_NAME} ${DSPLibSources})

target_include_directories(${PROJECT_NAME} PUBLIC ${MLAudioDir})

# target_link_libraries(${PROJECT_NAME}
# PUBLIC
    # MLCoreLib
# )
