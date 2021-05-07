cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")


#Set project information
project(smart_code VERSION 1.1.1 LANGUAGES CXX)

include(build/BuildDefaults.cmake)


# Set variables for target install and .pc pkg-config file
include(build/cmake/PrepareInstall.cmake)


# smart code SDK targets.
add_subdirectory("design_pattern")

# Create .pc pkg-config file
include(build/cmake/GeneratePkgConfig.cmake)
