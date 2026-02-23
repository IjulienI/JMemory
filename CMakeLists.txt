cmake_minimum_required(VERSION 4.0)
project(Custom_memory_allocator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set (SOURCES
    src/main.cpp
)

add_executable(CustomMemoryAllocator ${SOURCES})
target_include_directories(CustomMemoryAllocator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
