Loop order changed to access matrices' rows B and output sequentially (row-major) instead of column-major.

### Setup

```bash
cd "2. matrix"
cc matrix-multiply.c benchmark.c -o bin/benchmark
./bin/benchmark 1024
```

### Before (row-col-k loop order)

```c
for (int row = 0; row < a_rows; row++) {
  for (int col = 0; col < b_cols; col++) {
    output[row][col] = 0;
    for (int k = 0; k < a_cols; k++)
      output[row][col] += A[row][k] * B[k][col];
  }
}
```

### After - more cache friendly, matrices B and output are accessed sequentially

```c
for (int row = 0; row < a_rows; row++) {
  for (int k = 0; k < a_cols; k++) {
    double a_val = A[row][k];
    for (int col = 0; col < b_cols; col++) {
      output[row][col] += a_val * B[k][col];
    }
  }
}
```

### Performance comparison

```
-------------------------------------------------
| Size    | Naive    | Fast     | Speedup       |
-------------------------------------------------
| 128     | 0.012s   | 0.009s   | 1.34x         |
-------------------------------------------------
| 1024    | 17.074s  | 4.561s   | 3.74x         |
-------------------------------------------------
```

Speedup increases with matrix size because larger matrices exceed cache capacity, making the naive version more costly.
