//
// Created by julien on 3/5/26.
//

#include <catch2/catch_test_macros.hpp>
#include <JMemory/LinearAllocator.h>

TEST_CASE("LinearAllocator Basic Allocation", "[LinearAllocator]")
{
    JMemory::LinearAllocator allocator(1024, true);

    SECTION("Simple allocation")
    {
        void* ptr = allocator.Allocate(128);
        REQUIRE(ptr != nullptr);
    }

    SECTION("Aligment check")
    {
        void* ptr = allocator.Allocate(10, 64);
        REQUIRE(reinterpret_cast<uintptr_t>(ptr) % 64 == 0);
    }

    SECTION("Clear and Reuse")
    {
        allocator.Allocate(512);
        allocator.Clear();
        void* ptr = allocator.Allocate(1024);
        REQUIRE(ptr != nullptr);
    }

    SECTION("Overflow")
    {
        allocator.Allocate(1000);
        REQUIRE_THROWS_AS(allocator.Allocate(100), std::logic_error);
    }
}

TEST_CASE("LinearAllocator Clear Behavior", "[LinearAllocator]") {
    JMemory::LinearAllocator allocator(1024, true);

    int* ptr1 = static_cast<int*>(allocator.Allocate(sizeof(int)));
    *ptr1 = 42;

    allocator.Clear();

    REQUIRE(*ptr1 == 42);

    int* ptr2 = static_cast<int*>(allocator.Allocate(sizeof(int)));

    REQUIRE(ptr1 == ptr2);

    *ptr2 = 99;
    REQUIRE(*ptr1 == 99);
}