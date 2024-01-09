cmake_minimum_required(VERSION 3.20.0)

project(ulog)

include_directories(
    .
    ./include
)
    
link_directories(
    .
)

list(APPEND ULOG_SRC_LIST
    ./main.c
    ./ulog_buffers.c
    ./ulog_linux.c
    ./ulog.c
)

add_executable(ulog
    ${ULOG_SRC_LIST}
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread -lrt -T ${CMAKE_SOURCE_DIR}/link.lds")

set(CMAKE_C_FLAGS   "-std=gnu17 -O0 -g")             # gnu99
