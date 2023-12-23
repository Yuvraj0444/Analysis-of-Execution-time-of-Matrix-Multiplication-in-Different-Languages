#include <stdio.h>
#include <stdlib.h>

#define N 500  // Change the value of N for different matrix sizes

// Function to print a matrix
void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], result[N][N];

    // Initialize matrices with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat1[i][j] = rand() % 10; // Assign random values between 0 and 9
            mat2[i][j] = rand() % 10;
        }
    }

    printf("Matrix 1:\n");
    printMatrix(mat1);

    printf("\nMatrix 2:\n");
    printMatrix(mat2);

    // Multiply matrices and store the result in the 'result' matrix
    multiplyMatrices(mat1, mat2, result);

    printf("\nResultant Matrix:\n");
    printMatrix(result);

    return 0;
}
