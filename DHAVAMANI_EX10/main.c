#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function to add two matrices
void addMatrices(int *mat1, int *mat2, int *result, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        *(result + i) = *(mat1 + i) + *(mat2 + i);
    }
}

// Function to multiply two matrices
void multiplyMatrices(int *mat1, int *mat2, int *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = 0;
            for (int k = 0; k < cols; k++) {
                *(result + i * cols + j) += 
                    (*(mat1 + i * cols + k)) * (*(mat2 + k * cols + j));
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int *mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(mat + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int mat1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];

    printf("Matrix 1:\n");
    displayMatrix((int *)mat1, ROWS, COLS);

    printf("\nMatrix 2:\n");
    displayMatrix((int *)mat2, ROWS, COLS);

    printf("\nMatrix Addition:\n");
    addMatrices((int *)mat1, (int *)mat2, (int *)result, ROWS, COLS);
    displayMatrix((int *)result, ROWS, COLS);

    printf("\nMatrix Multiplication:\n");
    multiplyMatrices((int *)mat1, (int *)mat2, (int *)result, ROWS, COLS);
    displayMatrix((int *)result, ROWS, COLS);

    return 0;
}