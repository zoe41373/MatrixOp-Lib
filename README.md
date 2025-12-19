#include "matrix.h"

int main() {
    Matrix3x3 A = {{1,2,3},{4,5,6},{7,8,9}};
    Matrix3x3 B = {{9,8,7},{6,5,4},{3,2,1}};
    Matrix3x3 result;
    
    matrix_add(A, B, result);  
    matrix_mul(A, B, result); 
    
    float det = matrix_det(A);
    matrix_inverse(A, result);
    
    return 0;
}
