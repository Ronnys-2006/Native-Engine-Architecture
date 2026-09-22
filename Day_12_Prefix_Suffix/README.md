# Day 12: Prefix Suffix Product

## Brute Force Approach
For each index `i`, loop over the entire array and multiply every element except `nums[i]`. This is O(n) work per index, over n indices, giving O(n²) time and O(1) extra space (excluding output). The redundant work: for adjacent indices `i` and `i+1`, almost the entire product is recomputed from scratch even though only one term differs.

## Optimal (Best) Approach — Prefix/Suffix Product
Every answer is `(product of everything to the left) * (product of everything to the right)`. Build the left products first: `answer[i]` holds the product of all elements before index `i`, computed in a single left-to-right pass by carrying forward the running product. Then walk right-to-left, maintaining a running `suffix` product of everything seen so far (to the right), and multiply it into `answer[i]`. Each index is touched twice total, so this is O(n) time and O(1) extra space beyond the output array — and crucially avoids division, which would break on any zero in the array.

## Game Dev Application
This exact prefix/suffix pattern shows up in influence-map and "everyone except me" calculations in real-time systems — e.g. computing each enemy's threat contribution to a group excluding itself (for flocking/formation logic), or in a physics solver computing the combined force on a body from all other bodies except itself without recomputing the full sum for each body every tick. The O(n) two-pass trick is what keeps that kind of "all-but-self" aggregation off the O(n²) path in a per-frame budget.
