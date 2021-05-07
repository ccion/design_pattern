project(proxy_pattern)
add_executable(proxy_pattern  proxy_pattern.cpp)
target_include_directories(proxy_pattern PUBLIC "${proxy_pattern_SOURCE_DIR}")