Slow app is updated so as to do row-major iteration instead of column-major to access memory sequentially

### Setup

```bash
cd "1. grayscale"
gcc -O0 -g -o bin/grayscale grayscale.c -lm
valgrind --tool=cachegrind --cache-sim=yes ./bin/grayscale
```

### Performance comparison

```
---------------------------------------------------
| Metric       | Old     | New      | Improvement |
---------------------------------------------------
| D1 miss rate | 3.2%    | 0.1%     | 32x faster  |
---------------------------------------------------
| D1 misses    | 24.9M   | 1.1M     | 22 fewer    |
---------------------------------------------------
| Elapsed      | 9.7 s   | 7.3 s    | 25% faster  |
---------------------------------------------------
| Instructions | 1.667B  | 1.667B   | same        |
---------------------------------------------------
```
