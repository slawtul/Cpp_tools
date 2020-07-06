project(Playground_lib)

set(HEADER_FILES Playground.h)
set(SOURCE_FILES Playground.cpp)

add_library(Playground_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})