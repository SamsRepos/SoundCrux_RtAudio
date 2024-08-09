@echo off
rem Delete the build directory if it exists
if exist build rmdir /S /Q build

cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug

rem Pause the command prompt to see output (optional)
pause
