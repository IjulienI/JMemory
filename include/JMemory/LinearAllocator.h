//
// Created by julien on 3/5/26.
//

#ifndef JMEMORY_LINEARALLOCATOR_H
#define JMEMORY_LINEARALLOCATOR_H

#include <cassert>
#include <stdexcept>
#include <cstdint>

#include "Allocator.h"

namespace JMemory
{
    class LinearAllocator
    {
    public:
        LinearAllocator(size_t totalSize, bool autoInit = false)
        : m_Buffer(nullptr), m_BufferLength(totalSize), m_Offset(0)
        {
            // I don't know if this can reduce de performances, ofc it does but need to check how much (it's just an if)
            if (autoInit)
            {
                Init();
            }
        };

        ~LinearAllocator()
        {
            // Auto free on destruction
            if (m_Buffer)
            {
                free(m_Buffer);
            }
        }

        void Init()
        {
            // Initializing the buffer storage
            if (!m_Buffer)
            {
                m_Buffer = static_cast<uint8_t*>(malloc(m_BufferLength));
                m_Offset = 0;
            }
        }

        void* Allocate(size_t size, size_t alignment = alignof(std::max_align_t))
        {
            // Process the absolute address
            uintptr_t currentAddress = reinterpret_cast<uintptr_t>(m_Buffer) + m_Offset;
            // Find the next aligned address
            uintptr_t alignedAddress = (currentAddress + (alignment - 1)) & ~(alignment - 1);
            // Process the new offset
            size_t newOffset = (alignedAddress - reinterpret_cast<uintptr_t>(m_Buffer)) + size;

            // Check if the buffer can store the data
            if (newOffset <= m_BufferLength)
            {
                m_Offset = newOffset;
                return reinterpret_cast<void*>(alignedAddress);
            }

            // These lines are only for unit testing purposes
#ifdef JMEMORY_TEST_MODE
            throw std::logic_error("LinearAllocator Overflow");
#else
            assert(false && "LinearAllocator Overflow");
#endif

            return nullptr;
        }

        void Free(void*)
        {
            // Did nothing on a LinearAllocator. You need to clear all the Allocator to free data.
        }

        void Clear()
        {
            // Not really clear it. Just put the offset to 0 to override old data. (The old objects are not nullptr)
            // Be careful, the destuctors of the old objects is not called!
            m_Offset = 0;
        }

    private:
        uint8_t* m_Buffer;
        size_t m_BufferLength;
        size_t m_Offset;
    };

    static_assert(Allocator<LinearAllocator>);
}

#endif //JMEMORY_LINEARALLOCATOR_H