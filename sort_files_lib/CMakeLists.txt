project(sort_files_lib)

set(HEADER_FILES sort_files.h)
set(SOURCE_FILES sort_files.cpp)

add_library(sort_files_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
