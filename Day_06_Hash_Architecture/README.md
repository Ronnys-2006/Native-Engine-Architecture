# Day 6: Hash Map Architecture ($O(1)$ Lookups)

## The Engineering Problem
Searching unsorted datasets requires an $O(n)$ linear scan. For massive databases or real-time game inventories, scanning every element per frame causes severe latency. We need a way to look up specific data points instantly, regardless of the dataset size or sorting order.

## The Architecture: Hash Functions & Key-Value Pairs
Instead of scanning, we use a `std::unordered_map` (Hash Map). The target value acts as a "Key". A mathematical hash function converts this Key directly into a physical memory address, allowing the CPU to jump straight to the data in $O(1)$ time. 

In the Unsorted Two Sum problem, as we iterate through the array, we calculate the exact complement needed to reach the target (`target - current_value`). We immediately check the Hash Map for this complement. If it exists, we return the indices. If not, we store the current value and its index in the Hash Map for future lookups.

## The Hardware Trade-off (Time vs. Space)
This is the fundamental trade-off in computer science. By allocating extra memory on the heap to build the Hash Map ($O(n)$ space), we bypass the need for nested loops, reducing the time complexity from $O(n^2)$ to $O(n)$. We sacrifice RAM to buy CPU speed.

## Complexity Profile
* **Time Complexity:** $O(n)$ - A single pass through the array. Hash Map insertions and lookups take $O(1)$ average time.
* **Space Complexity:** $O(n)$ - Worst-case scenario, we allocate $N-1$ elements in the dynamically sized Hash Map.