@echo off
rem Delete the build directory if it exists
rmdir /S /Q build

rem Run CMake to configure the project and generate build files
cmake -S . -B build -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

rem Build the project
cmake --build build --config Debug

rem Pause the command prompt to see output (optional)
pause
