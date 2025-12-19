#include <stdio.h>
#include "matrix.h"

int main() {
    printf("=== 3x3 矩陣運算庫測試 ===\n\n");
    
    Matrix3x3 A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    Matrix3x3 B = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    Matrix3x3 result;
    
    printf("矩陣 A:\n");
    matrix_print(A);
    printf("\n矩陣 B:\n");
    matrix_print(B);
    
    printf("\n1. 加法 A + B:\n");
    matrix_add(A, B, result);
    matrix_print(result);
    
    printf("\n2. 减法 A - B:\n");
    matrix_sub(A, B, result);
    matrix_print(result);
    
    printf("\n3. 逐元素乘法 A * B (element-wise):\n");
    matrix_elementwise_mul(A, B, result);
    matrix_print(result);
    
    printf("\n4. 矩陣乘法 A * B:\n");
    matrix_mul(A, B, result);
    matrix_print(result);
    
    printf("\n5. 轉置 A^T:\n");
    matrix_transpose(A, result);
    matrix_print(result);
  
    Matrix3x3 C = {
        {4, 7, 2},
        {3, 5, 1},
        {2, 3, 2}
    };
    
    printf("\n=== 可逆矩陣測試 ===\n");
    printf("矩陣 C:\n");
    matrix_print(C);
    
    printf("\n6. 行列式 det(C): %.2f\n", matrix_det(C));
    
    printf("\n7. 伴随矩陣 adj(C):\n");
    matrix_adjoint(C, result);
    matrix_print(result);
    
    printf("\n8. 逆矩陣 C^(-1):\n");
    if (matrix_inverse(C, result)) {
        matrix_print(result);
    }
    
    printf("\n=== 測試完成 ===\n");
    return 0;
}
