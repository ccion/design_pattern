project(singleton_pattern)
add_executable(singleton_pattern  singleton_pattern_test.cpp singleton_pattern.cpp)
target_include_directories(singleton_pattern PUBLIC "${singleton_pattern_SOURCE_DIR}")