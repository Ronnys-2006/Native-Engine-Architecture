# Day 9: Profit Optimization

## Brute Force Approach
Check every possible pair of a buy day and a later sell day, compute the profit for each pair, and track the maximum found. Every earlier price gets re-compared against every later price individually, so the same starting point is revisited once for each possible day it could be sold against.

**Time Complexity:** $O(n^2)$ — every pair of days compared
**Space Complexity:** $O(1)$

## Optimal (Best) Approach — Single-Pass Min Tracking
Make one pass while tracking two rolling values: the lowest price seen so far, and the best profit achievable so far. At each day, check what profit selling today against the lowest price seen before it would yield, and update the best profit if it's higher — then update the running lowest price if today's is a new low. This works because the only earlier price that can ever produce the best future profit is the cheapest one seen so far; every other earlier price can only tie or lose against it.

**Time Complexity:** $O(n)$ — single pass, constant work per element
**Space Complexity:** $O(1)$ — two scalar variables (`maxprofit`, `bestbuy`)

## Game Dev Application
The "track the best baseline seen so far, measure everything after against it" pattern fits gameplay economy and analytics systems directly — a dynamic in-game market could use the same running-minimum logic to flag the cheapest point a resource ever hit, letting the game surface "you could have bought this for X% less" without storing the entire price history. The same shape also works for a difficulty or skill-tracking system measuring a player's biggest recovery from a performance dip across a session — track the running minimum score, and the best recovery spread from it, in a single pass.