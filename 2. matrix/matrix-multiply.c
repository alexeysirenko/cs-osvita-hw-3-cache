/*
Naive code for multiplying two matrices together.

There must be a better way!
*/

#include <stdio.h>
#include <stdlib.h>

/*
  A naive implementation of matrix multiplication.

  DO NOT MODIFY THIS FUNCTION, the tests assume it works correctly, which it
  currently does
*/
void matrix_multiply(double **output, double **A, double **B, int a_rows, int a_cols,
                     int b_cols) {
  for (int row = 0; row < a_rows; row++) {
    for (int col = 0; col < b_cols; col++) {
      output[row][col] = 0;
      for (int k = 0; k < a_cols; k++)
        output[row][col] += A[row][k] * B[k][col];
    }
  }
}

void fast_matrix_multiply(double **output, double **A, double **B, int a_rows,
                          int a_cols, int b_cols) {
  for (int row = 0; row < a_rows; row++)
    for (int col = 0; col < b_cols; col++)
      output[row][col] = 0;

  for (int row = 0; row < a_rows; row++) {
    for (int k = 0; k < a_cols; k++) {
      double a_val = A[row][k];
      for (int col = 0; col < b_cols; col++) {
        output[row][col] += a_val * B[k][col];
      }
    }
  }
}
