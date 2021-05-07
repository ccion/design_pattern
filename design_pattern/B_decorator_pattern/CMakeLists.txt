project(decorator_pattern)
add_executable(decorator_pattern  decorator_pattern_test.cpp decorator_pattern.cpp)
target_include_directories(decorator_pattern PUBLIC "${decorator_pattern_SOURCE_DIR}")