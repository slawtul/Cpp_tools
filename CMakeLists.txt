cmake_minimum_required(VERSION 3.15)
project(Cpp_tools)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# sort_files program
add_executable(sort_files sort_files_run.cpp)
include_directories(sort_files_lib)
add_subdirectory(sort_files_lib)
target_link_libraries(sort_files sort_files_lib)

# playground program
add_executable(playground playground_run.cpp)
include_directories(playground_lib)
add_subdirectory(playground_lib)
target_link_libraries(playground playground_lib)

# tests
add_subdirectory(catch_tests)
