project(Safaga)
cmake_minimum_required(VERSION 3.6.0)
mark_as_advanced(CMAKE_TOOLCHAIN_FILE)

# set the root dir
get_filename_component(ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

message(STATUS "CMAKE_CURRENT_LIST_DIR: " ${CMAKE_CURRENT_LIST_DIR})
message(STATUS "Source tree root: " ${ROOT_DIR})

# Set output and install locations
message(STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(OpenGL REQUIRED)

# Commands like include() and find_package() search for files in directories 
# listed by this variable before checking the default modules that come with CMake.
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${ROOT_DIR}/build/cmake
    ${ROOT_DIR}/build/platforms)

# Check if toolchain specified
if(NOT SAFAGA_PLATFORM_WINDOWS AND NOT SAFAGA_PLATFORM_ANDROID)
    message(FATAL_ERROR "No toolchain file set")
endif()

# set Options to user
option(BUILD_APPS "Build Apps" ON)

# Include macros and definations
include(Definations)
include(CompilerOptions)
include(BuildMacros)

#Set Compiler Options
set_compiler_option()

# Add module subdirectory
add_subdirectory("modules")

#Add 3rdParty subdirectory
#add_subdirectory("3rdparty")

if(BUILD_APPS)
    add_subdirectory("apps")
endif()
