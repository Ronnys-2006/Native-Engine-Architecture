# Day 2: Linear Optimization (Two-Pointer Architecture)

## The Engineering Problem
Finding a pair of elements that sum to a specific target within a sorted array. The naive approach relies on nested `for` loops, comparing every element against every other element. This results in an $O(n^2)$ time complexity. For an array of 10,000 items, this is 100,000,000 CPU operations—enough to instantly stall a game loop thread. 

## The Architecture: Two-Pointer Traversal
Because the array is pre-sorted, we can mathematically guarantee the direction of growth. We deploy two index trackers:
* `start`: Points to index 0 (the lowest value).
* `end`: Points to index `size - 1` (the highest value).

### Execution Rules
The pointers move inward dynamically based on the current sum:
1. **If `arr[start] + arr[end] == target`:** Match found. Return indices.
2. **If `arr[start] + arr[end] < target`:** The sum is too low. We increment the `start` pointer to increase the total sum.
3. **If `arr[start] + arr[end] > target`:** The sum is too high. We decrement the `end` pointer to decrease the total sum.

## Hardware Reality Check
While an unsorted array could be solved in $O(n)$ time using a Hash Map, Hash Maps require dynamically allocating $O(n)$ extra memory on the heap. By ensuring the data is sorted and using Two Pointers, we solve the problem in strictly $O(1)$ space, completely bypassing the memory allocator and the garbage collector.

## Complexity Profile
* **Time Complexity:** $O(n)$ - The pointers never cross or backtrack; maximum $N$ operations.
* **Space Complexity:** $O(1)$ - Sorted entirely in-place without auxiliary data structures.
