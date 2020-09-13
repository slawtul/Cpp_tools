project(playground_lib)

set(HEADER_FILES playground.h)
set(SOURCE_FILES playground.cpp)

add_library(playground_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
