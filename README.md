# Custom memory allocators

This repository is currently in the foundational phase.
The goal of this project is to build a suite of custom memory allocators in C++ from scratch.
As the first building block of a Data-Oriented game engine, this project aims to demonstrate how manual memory management can drastically outperform standard OS allocations (malloc/new) by preventing memory fragmentation and ensuring cache-friendly data alignment.

## What I plan to implement :

- [ ] Linear Allocator
- [ ] Stack Allocator
- [ ] Pool Allocator
- [ ] Benchmarks comparing custom allocators to standard malloc/new

## Sources and references : 
- [Giger Bill - Memory allocation strategies ](https://www.gingerbill.org/series/memory-allocation-strategies/)
- [Bitsquid - Custom Memory Allocation in C++ ](https://bitsquid.blogspot.com/2010/09/custom-memory-allocation-in-c.html)
- [Sem Laan - Portfolio C++ and custom memory allocators](https://semlaanportfolio.nl/c-custom-memory-allocators-and-raii/)
- [Jason Gregory - Game Engine Architecture](https://www.gameenginebook.com/)
- [Mike Acton - Data-Oriented Design and C++](https://youtu.be/rX0ItVEVjHc?si=dJB75XT0kBzWcBQv)

## Roadmap : 
- **Phase 1** : Define the base virtual Allocator Interface.
- **Phase 2** : Implement the core logic for Linear, Stack and Pool allocators.
- **Phase 3** : Build the benchmarking application and analyze the data.
- **Phase 4** : Integrate the memory system into a core engine to support the upcoming ECS architecture.

## Note : 
This project is for personal learning and experimentation purposes.
The code can have some issues and is not intended to be perfect.
This readme will be updated as the project progresses, it's going to serve as a documentation of what I have learned and implemented.
