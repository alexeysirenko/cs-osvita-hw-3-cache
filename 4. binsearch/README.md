### Setup

```bash
cd "4. binsearch"
gcc -O2 -o bin/bins-bench bins-bench.c
./bins-bench 25 10 1000000
```

### Benchmark results

```
Array A (2^25 elements):         ~0.96s
Array B (2^25 + 2^10 elements):  ~0.70s
Speedup: ~1.37x faster on larger array
```

### Explanation

Power-of-2 array sizes cause binary search positions (n/2, n/4, n/8) to map to the same cache set, resulting in conflict misses. Adding 2^10 elements breaks this alignment, spreading accesses across different cache sets.

Cache performance depends on access pattern alignment, not just data size.
