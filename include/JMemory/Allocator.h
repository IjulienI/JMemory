//
// Created by julien on 3/5/26.
//

#ifndef JMEMORY_ALLOCATOR_H
#define JMEMORY_ALLOCATOR_H

#include <cstddef>
#include <concepts>

namespace JMemory
{
    template<typename T>
    concept Allocator = requires(T allocator, size_t size, size_t alignment, void* ptr)
    {
        {allocator.Allocate(size, alignment)} -> std::same_as<void*>;
        {allocator.Free(ptr)} -> std::same_as<void>;
        {allocator.Init()} -> std::same_as<void>;
        {allocator.Clear()} -> std::same_as<void>;
    };
}

#endif //JMEMORY_ALLOCATOR_H