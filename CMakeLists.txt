cmake_minimum_required(VERSION 3.20)
project(JMemory VERSION 1.0.0 LANGUAGES CXX)

add_library(JMemory INTERFACE)

target_include_directories(JMemory
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(JMemory INTERFACE cxx_std_20)

target_sources(JMemory INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
        include/JMemory/Allocator.h
        include/JMemory/LinearAllocator.h
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(FetchContent)

    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.4.0
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(JMemoryTests tests/LinearAllocatorTest.cpp)
    target_link_libraries(JMemoryTests PRIVATE JMemory Catch2::Catch2WithMain)

    target_compile_definitions(JMemoryTests PRIVATE JMEMORY_TEST_MODE)

    enable_testing()
    include(Catch)
    catch_discover_tests(JMemoryTests)
endif ()
