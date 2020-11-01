cmake_minimum_required(VERSION 3.16)
project(nlohmann_json_glm C CXX)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

cmake_policy(SET CMP0077 NEW) # set() overrides option()

#--------------------------------
# Debug Options
#--------------------------------

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>") # Define DEBUG in Debug builds

#--------------------------------
# Compiler configuration
#--------------------------------

if(MINGW)
    set(WIN32 ON)
endif()

#--------------------------------
# External libraries
#--------------------------------

add_subdirectory(lib)

#--------------------------------
# Source
#--------------------------------

add_library(nlohmann_json_glm INTERFACE)
target_include_directories(nlohmann_json_glm INTERFACE src/)

target_link_libraries(nlohmann_json_glm INTERFACE glm nlohmann_json)

#--------------------------------
# Tests
#--------------------------------

if(BUILD_TESTING)
    include(CTest)
    enable_testing()

    add_subdirectory(tests)
endif()
