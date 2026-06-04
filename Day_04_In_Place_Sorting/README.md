# Day 4: In-Place Sorting Architecture (Dutch National Flag)

## The Engineering Problem
Sorting arrays of categorized data (like render distances, team IDs, or inventory priorities) using standard `$O(n \log n)$` functions or nested `$O(n^2)$` loops wastes CPU cycles. The objective is to sort three distinct integers (`0`, `1`, `2`) in a single pass without allocating new heap memory.

## The Architecture: Three-Pointer Traversal
Instead of counting and rewriting, we use the Dutch National Flag (DNF) algorithm to physically swap memory addresses during a single traversal. 

The array is divided into bounds using three pointers (`low`, `mid`, `high`):
* `[0 to low-1]`: Reserved for `0`s.
* `[low to mid-1]`: Reserved for `1`s.
* `[mid to high]`: Unexplored memory.
* `[high+1 to end]`: Reserved for `2`s.

### Execution Rules
The scanner (`mid`) checks the current index until it crosses the `high` bound:
1.  **If 0:** Swap with `low`. Increment both `low` and `mid`.
2.  **If 1:** Do nothing. Increment `mid`.
3.  **If 2:** Swap with `high`. Decrement `high`. **(Do not increment mid, as the swapped value is unexplored).**

## Complexity Profile
* **Time Complexity:** `$O(n)$` - The array is traversed exactly once.
* **Space Complexity:** `$O(1)$` - Sorted entirely in-place.