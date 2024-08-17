cmake_minimum_required(VERSION 3.15)
project(SoundCrux_RtAudio VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_GENERATOR_PLATFORM x64)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source directory
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create a static library
add_library(SoundCrux_RtAudio STATIC ${SOURCES})

# Find RtAudio package
find_package(RtAudio REQUIRED)

# Specify include directories for SoundCrux_RtAudio
target_include_directories(SoundCrux_RtAudio PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link RtAudio to SoundCrux_RtAudio
target_link_libraries(SoundCrux_RtAudio PUBLIC RtAudio::rtaudio)
