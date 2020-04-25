project(Sort_files_lib)

set(HEADER_FILES Sort_files.h)
set(SOURCE_FILES Sort_files.cpp)

add_library(Sort_files_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})