@echo off
rem Delete the build directory if it exists
if exist build rmdir /S /Q build

rem Run CMake to configure the project and generate build files
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

rem Build the project
cmake --build build

rem Pause the command prompt to see output (optional)
pause
