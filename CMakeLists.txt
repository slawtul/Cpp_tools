cmake_minimum_required(VERSION 3.15)
project(Cpp_tools)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# sort_files program
add_executable(sort_files Sort_files_run.cpp)
include_directories(Sort_files_lib)
add_subdirectory(Sort_files_lib)
target_link_libraries(sort_files Sort_files_lib)

# tests
add_subdirectory(Catch_tests)