Slow app is updated so as to do row-major iteration instead of column-major to access memory sequentially

### Setup

```bash
cd "1. grayscale"
gcc -O0 -g -o bin/grayscale grayscale.c -lm
valgrind --tool=cachegrind --cache-sim=yes ./bin/grayscale
```

### Performance comparison:

Old slow column-major traversal:
