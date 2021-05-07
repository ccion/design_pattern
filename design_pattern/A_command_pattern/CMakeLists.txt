project(command_pattern)
add_executable(command_pattern test_command_pattern.cpp command_pattern.cpp)
target_include_directories(command_pattern PUBLIC "${command_pattern_SOURCE_DIR}")