project(state_pattern)
add_executable(state_pattern test_state_pattern.cpp state_pattern.cpp )
target_include_directories(state_pattern PUBLIC "${state_pattern_SOURCE_DIR}")