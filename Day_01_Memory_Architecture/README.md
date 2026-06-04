# Day 1: Native Memory Architecture & Spatial Locality

## The Engineering Problem
In high-performance C++ environments like Unreal Engine, processing massive arrays of data (e.g., thousands of projectiles or AI agents) must happen within a 16ms frame window. Passing data "by value" into a range-based loop forces the CPU to create temporary copies of every element on the stack memory, hiding the true data source and wasting valuable CPU cycles.

## The Architecture: Pass by Reference
To interact with raw metal, data must be passed by reference using the address-of operator (`&`). This creates an alias directly pointing to the original memory block on the heap, bypassing the stack copy completely.

### Spatial Locality
Standard C++ `std::vector` objects guarantee contiguous memory allocation. When iterating by reference, inspecting the raw hexadecimal memory addresses reveals exactly a 4-byte jump between each integer (32-bit). This contiguous layout allows the CPU to load chunks of data directly into the L1/L2 cache, preventing cache misses and avoiding frame drops.

## Hardware Reality Check
If you attempt to log the address of a standard by-value loop variable (`&val`), the console will output the exact same hexadecimal stack address every loop iteration. It is merely printing the address of the temporary bucket, not the data itself.

## Complexity Profile
* **Time Complexity:** `$O(n)$` - Single traversal.
* **Space Complexity:** `$O(1)$` - Zero new memory allocated (due to reference passing).