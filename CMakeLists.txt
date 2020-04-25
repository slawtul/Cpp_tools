cmake_minimum_required(VERSION 3.15)
project(Cpp_tools)

set(CMAKE_CXX_STANDARD 20)
add_executable(Sort_files_run Sort_files_run.cpp)

include_directories(Sort_files_lib)
add_subdirectory(Sort_files_lib)

target_link_libraries(Sort_files_run Sort_files_lib)

add_subdirectory(Catch_tests)