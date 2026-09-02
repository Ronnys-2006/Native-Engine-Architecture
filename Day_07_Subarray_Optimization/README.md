# Day 7: Subarray Optimization ($O(n)$ Kadane's Algorithm)

## The Engineering Problem
Given a sequence of signed values, find the maximum sum achievable from any *contiguous* run. The naive approach checks every possible (start, end) pair and sums between them — for $n$ elements that's $O(n^2)$ pairs, or $O(n^3)$ if the sum is recomputed from scratch for every pair instead of extending a running total. In a real-time system — scanning a frame-time buffer for the worst contiguous stretch, or a combo/score buffer for a player's best streak — re-scanning every window per frame is a non-starter.

## The Architecture: Kadane's Algorithm (Local vs. Global State)
Instead of re-summing from scratch, we track two rolling scalars across a single pass: `currsum`, the best sum of a subarray *ending exactly at the current index*, and `maxsum`, the best sum seen *anywhere so far*. At each element we extend `currsum` by the current value. If `currsum` ever drops below zero, it can only drag down every future sum attached to it — so we discard it and restart at zero from the next index. This is the core greedy insight: a negative running total is never worth carrying forward, only worth abandoning.

## The Hardware Trade-off (Zero Auxiliary Memory)
Where Day 6's Hash Map traded space for time ($O(n)$ memory to buy $O(1)$ lookups), Kadane's needs no trade-off at all. There's no heap allocation and no auxiliary structure — just two registers updated in a single linear pass. It's the rare case where you get both axes for free: $O(n)$ time *and* $O(1)$ space, because the algorithm only ever needs "the best I've built so far" and "the best I've ever seen," never the full history.

## Complexity Profile
* **Time Complexity:** $O(n)$ — a single pass through the array, constant work per element.
* **Space Complexity:** $O(1)$ — two scalar variables (`currsum`, `maxsum`); no data structure grows with input size.