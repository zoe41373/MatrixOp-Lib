#include "matrix.h"
#include <stdio.h>
#include <math.h>

void matrix_add(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_sub(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_elementwise_mul(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}

void matrix_mul(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_transpose(Matrix3x3 a, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = a[i][j];
        }
    }
}

static float det2x2(float a, float b, float c, float d) {
    return a * d - b * c;
}

float matrix_det(Matrix3x3 a) {
    return a[0][0] * det2x2(a[1][1], a[1][2], a[2][1], a[2][2]) -
           a[0][1] * det2x2(a[1][0], a[1][2], a[2][0], a[2][2]) +
           a[0][2] * det2x2(a[1][0], a[1][1], a[2][0], a[2][1]);
}

void matrix_adjoint(Matrix3x3 a, Matrix3x3 adj) {
    float cofactor[SIZE][SIZE];
    
    cofactor[0][0] =  det2x2(a[1][1], a[1][2], a[2][1], a[2][2]);
    cofactor[0][1] = -det2x2(a[1][0], a[1][2], a[2][0], a[2][2]);
    cofactor[0][2] =  det2x2(a[1][0], a[1][1], a[2][0], a[2][1]);
    
    cofactor[1][0] = -det2x2(a[0][1], a[0][2], a[2][1], a[2][2]);
    cofactor[1][1] =  det2x2(a[0][0], a[0][2], a[2][0], a[2][2]);
    cofactor[1][2] = -det2x2(a[0][0], a[0][1], a[2][0], a[2][1]);
    
    cofactor[2][0] =  det2x2(a[0][1], a[0][2], a[1][1], a[1][2]);
    cofactor[2][1] = -det2x2(a[0][0], a[0][2], a[1][0], a[1][2]);
    cofactor[2][2] =  det2x2(a[0][0], a[0][1], a[1][0], a[1][1]);
    
    matrix_transpose(cofactor, adj);
}

int matrix_inverse(Matrix3x3 a, Matrix3x3 inv) {
    float det = matrix_det(a);
    
    if (fabs(det) < 1e-6) {
        printf("矩陣不可逆（行列式为0）\n");
        return 0;
    }
    
    Matrix3x3 adj;
    matrix_adjoint(a, adj);
    
    // A^(-1) = (1/det) * adj(A)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }
    return 1;
}

void matrix_print(Matrix3x3 a) {
    for (int i = 0; i < SIZE; i++) {
        printf("| ");
        for (int j = 0; j < SIZE; j++) {
            printf("%6.2f ", a[i][j]);
        }
        printf("|\n");
    }
}

void matrix_set(Matrix3x3 a, float values[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = values[i][j];
        }
    }
}
