project(observer_pattern)
add_executable(observer_pattern observer_test.cpp observer_pattern.cpp)
target_include_directories(observer_pattern PUBLIC "${observer_pattern_SOURCE_DIR}")