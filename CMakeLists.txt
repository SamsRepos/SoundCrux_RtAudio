cmake_minimum_required(VERSION 3.15)
project(SoundCrux VERSION 1.0.0 LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source directory
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create a static library
add_library(SoundCrux STATIC ${SOURCES})

# Find RtAudio package
find_package(RtAudio REQUIRED)

# Specify include directories for SoundCrux
target_include_directories(SoundCrux PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link RtAudio to SoundCrux
target_link_libraries(SoundCrux PUBLIC RtAudio::rtaudio)
