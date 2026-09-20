# Day 11: Boundary Optimization

## Brute Force Approach
Check every possible pair of boundaries by trying all combinations of a left wall and a right wall, computing the area between them as the shorter wall's height times the distance separating them, and tracking the maximum. Every wall gets re-paired against every other wall individually, regardless of what's already been ruled out.

**Time Complexity:** $O(n^2)$ — every pair of walls compared
**Space Complexity:** $O(1)$

## Optimal (Best) Approach — Two Pointer (Converging Boundaries)
Start with the widest possible container — one pointer at the very first wall, one at the very last — and close the gap one step at a time. At each step, compute the area using the shorter of the two current walls, since that's always the limiting factor, then move whichever pointer is on the *shorter* wall inward. This is safe to do without ever checking the wall being abandoned again: keeping a shorter wall in place while narrowing the width can only ever shrink the area, since the width is dropping and the limiting height can't increase by holding onto the smaller side. Moving the taller wall's pointer, by contrast, could still find a wall tall enough to beat the current best even at a smaller width.

**Time Complexity:** $O(n)$ — each pointer moves at most n times total, single pass
**Space Complexity:** $O(1)$ — two index variables, no auxiliary structure

## Game Dev Application
This "always narrow from the constrained side" logic shows up in collision and containment checks — for example, computing the largest unobstructed rectangular area between two converging dynamic obstacles, or resolving a camera's safe-frame bounds by shrinking inward from whichever edge is currently the tighter constraint, rather than recalculating the full bounding check from scratch every time either edge moves.
