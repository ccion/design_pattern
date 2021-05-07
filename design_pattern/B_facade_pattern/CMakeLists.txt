project(facade_pattern)
add_executable(facade_pattern   facade_pattern.cpp)
target_include_directories(facade_pattern PUBLIC "${facade_pattern_SOURCE_DIR}")