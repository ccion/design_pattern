project(template_pattern)
add_executable(template_pattern template_pattern.cpp)
target_include_directories(template_pattern PUBLIC "${template_pattern_SOURCE_DIR}")