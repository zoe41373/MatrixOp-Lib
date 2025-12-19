#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

typedef float Matrix3x3[SIZE][SIZE];

void matrix_add(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void matrix_sub(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void matrix_elementwise_mul(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void matrix_mul(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void matrix_transpose(Matrix3x3 a, Matrix3x3 result);

float matrix_det(Matrix3x3 a);
void matrix_adjoint(Matrix3x3 a, Matrix3x3 adj);
int matrix_inverse(Matrix3x3 a, Matrix3x3 inv);

void matrix_print(Matrix3x3 a);
void matrix_set(Matrix3x3 a, float values[SIZE][SIZE]);

#endif
