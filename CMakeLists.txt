cmake_minimum_required(VERSION 3.14) # This is a version tested to work, earlier versions probably work as well.

project(shenk
        VERSION 0.0.1
        DESCRIPTION "CMake C++ template project with additional useful tools."
        LANGUAGES CXX)

# All compile commands are written to file "compile_commands.json".
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    message(WARNING "No build type set, default to Release. CMake can be run with e.g. -DCMAKE_BUILD_TYPE=Debug, Release, RelWithDebInfo.")
    set(CMAKE_BUILD_TYPE Release CACHE String "No build type set, we default to release." FORCE)
endif()

include(external/cppcheck.cmake)

add_subdirectory(src)