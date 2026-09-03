# Day 8: Consensus Architecture

## Brute Force Approach
For each candidate value, re-scan the entire array counting how many times it occurs, and check whether that count exceeds ⌊n/2⌋. Every candidate check re-walks the full array from scratch, so the same data gets scanned repeatedly for every distinct value tried.

**Time Complexity:** $O(n^2)$ — nested scan, every element checked against every other
**Space Complexity:** $O(1)$ — no extra structure, just counters

## Better Approach — Sort and Scan
Since the majority element occurs more than $n/2$ times, sorting the array guarantees it becomes dense enough to occupy the middle index — no other value can spread across the center of a sorted array without itself having a majority share. After sorting, a single linear scan confirms this by walking the array once and counting the run length of the current value, stopping as soon as any run exceeds $n/2$. The trade lands the other way from the brute force: less redundant scanning, at the cost of paying for the sort up front.

**Time Complexity:** $O(n \log n)$ — dominated by the sort, followed by one linear scan
**Space Complexity:** $O(\log n)$ — the recursion stack of an in-place comparison sort (or $O(1)$ extra beyond the sort itself)

## Optimal (Best) Approach — Boyer-Moore Voting Algorithm
Track a single candidate and a running vote count across one pass through the array. Each element matching the current candidate increments the count; each mismatch decrements it. Whenever the count hits zero, the current index becomes the new candidate — a "cancelled-out" run is treated as evidence the real majority lies elsewhere in what's left. Since the true majority element appears more than $n/2$ times, it can never be fully cancelled out by every other element combined, which guarantees the final surviving candidate is correct.

**Time Complexity:** $O(n)$ — single pass, no sort needed
**Space Complexity:** $O(1)$ — two scalar variables (`freq`, `ans`), no auxiliary structure

## Game Dev Application
This "cancel-out to find dominance" pattern fits systems that need a fast consensus check without a memory-heavy tally. A networking layer receiving several redundant client state reports each tick could use the same logic to pick the "majority" input and discard a single corrupted or malicious packet — no frequency table and no sort required, just a running candidate and count, which matters when this check has to run every tick under a hard time budget.