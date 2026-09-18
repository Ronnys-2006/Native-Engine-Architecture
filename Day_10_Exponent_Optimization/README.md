# Day 10: Exponent Optimization

## Brute Force Approach
Multiply x by itself n times in a straight loop, one multiplication per unit of the exponent. A negative exponent is handled by computing the positive version first and taking the reciprocal. The core inefficiency: computing x^16 this way takes 16 multiplications, when the answer only actually needs 4, since 16 is 2^4.

**Time Complexity:** $O(n)$
**Space Complexity:** $O(1)$

## Optimal (Best) Approach — Binary Exponentiation
Instead of counting up to n one multiplication at a time, decompose n into its binary representation. Repeatedly square the base ($x, x^2, x^4, x^8, ...$) while walking through n's bits from least to most significant, folding a squared value into the running answer only when that particular bit of n is 1. Every doubling of the exponent consumes exactly one bit, so the total number of multiplications is proportional to the number of *bits* in n, not the size of n itself. A negative n is handled by inverting the base once up front and running the same loop on the positive magnitude of n — with one subtlety: negating the most negative possible integer overflows a same-width signed type, so the exponent has to be widened to a genuinely larger type before the sign flip, not just copied into a same-size alias of it.

**Time Complexity:** $O(\log n)$
**Space Complexity:** $O(1)$

## The Portability Trap (`long` vs. `long long`)
The one line that actually decides correctness here is the type used to hold the exponent before negating it. `INT_MIN` cannot be negated as a same-width `int` — its positive equivalent doesn't fit in the same number of bits, so the negation silently overflows. Widening it into a `long` before flipping the sign is the right instinct, but the C++ standard only guarantees `long` is *at least* as wide as `int` — never guaranteed to be wider. On Linux, `long` happens to be 64-bit, so the bug is fully hidden and every test passes. On Windows (MinGW/MSVC, the LLP64 data model), `long` is only 32-bit — identical in size to `int` — so the exact overflow being guarded against still happens, silently, and `myPow(x, INT_MIN)` quietly returns the wrong value despite the "fix" being in place. `long long` is the correct type, because it's the smallest type the standard actually guarantees to be at least 64 bits on every platform, not just usually.

## Game Dev Application
Binary exponentiation's real payoff in engine code shows up anywhere a value gets raised to a power repeatedly under a tight frame budget — falloff curves for lighting or audio attenuation, compounding a growth rate across many levels of procedural subdivision, or fast power-of-two checks used throughout memory allocators and spatial partitioning structures like octrees and BVHs, where sizes are deliberately kept as powers of two specifically so operations like this collapse into simple bit shifts instead of loops.
