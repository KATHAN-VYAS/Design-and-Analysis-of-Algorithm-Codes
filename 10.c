#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to allocate memory for a matrix
int **allocate_matrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to initialize a matrix with random values
void initialize_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand()%10;    //Random values between 0 and 9
        }
    }
}

// recursive matrix multiplication
void recursive_matrix_multiplication(int **A, int **B, int **C, int rowA, int colA, int rowB, int colB, int size) {
    if (size == 1) {
        C[rowA][colB] += A[rowA][colA] * B[rowB][colB];
    } else {
        int newSize = size / 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    recursive_matrix_multiplication(A, B, C, rowA + i * newSize, colA + k * newSize, rowB + k * newSize, colB + j * newSize, newSize);
                }
            }
        }
    }
}

// Strassen's matrix multiplication
void strassen_matrix_multiplication(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = n / 2;
    int **A11 = allocate_matrix(newSize);
    int **A12 = allocate_matrix(newSize);
    int **A21 = allocate_matrix(newSize);
    int **A22 = allocate_matrix(newSize);
    int **B11 = allocate_matrix(newSize);
    int **B12 = allocate_matrix(newSize);
    int **B21 = allocate_matrix(newSize);
    int **B22 = allocate_matrix(newSize);
    int **C11 = allocate_matrix(newSize);
    int **C12 = allocate_matrix(newSize);
    int **C21 = allocate_matrix(newSize);
    int **C22 = allocate_matrix(newSize);
    int **M1 = allocate_matrix(newSize);
    int **M2 = allocate_matrix(newSize);
    int **M3 = allocate_matrix(newSize);
    int **M4 = allocate_matrix(newSize);
    int **M5 = allocate_matrix(newSize);
    int **M6 = allocate_matrix(newSize);
    int **M7 = allocate_matrix(newSize);

    // Partitioning input matrices into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating products
    recursive_matrix_multiplication(A11, B11, M1, 0, 0, 0, 0, newSize);
    recursive_matrix_multiplication(A12, B21, M2, 0, 0, 0, 0, newSize);
    recursive_matrix_multiplication(A11, B12, M3, 0, 0, 0, 0, newSize);
    recursive_matrix_multiplication(A12, B22, M4, 0, 0, 0, 0, newSize);
    recursive_matrix_multiplication(A21, B11, M5, 0, 0, 0, 0, newSize);
    recursive_matrix_multiplication(A22, B21, M6, 0, 0, 0, 0, newSize);
    recursive_matrix_multiplication(A21, B12, M7, 0, 0, 0, 0, newSize);

    // Calculating C matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C11[i][j] = M1[i][j] + M2[i][j];
            C12[i][j] = M3[i][j] + M4[i][j];
            C21[i][j] = M5[i][j] + M6[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M7[i][j];
        }
    }

    // Combining C matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Freeing memory
    free_matrix(A11, newSize);
    free_matrix(A12, newSize);
    free_matrix(A21, newSize);
    free_matrix(A22, newSize);
    free_matrix(B11, newSize);
    free_matrix(B12, newSize);
    free_matrix(B21, newSize);
    free_matrix(B22, newSize);
    free_matrix(C11, newSize);
    free_matrix(C12, newSize);
    free_matrix(C21, newSize);
    free_matrix(C22, newSize);
    free_matrix(M1, newSize);
    free_matrix(M2, newSize);
    free_matrix(M3, newSize);
    free_matrix(M4, newSize);
    free_matrix(M5, newSize);
    free_matrix(M6, newSize);
    free_matrix(M7, newSize);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int n = 2; // Start with a 2x2 matrix
    printf("n, recursive Time (s), Strassen Time (s)\n");
    while (n <= 1024) { // Increase n up to 1024
        int **A = allocate_matrix(n);
        int **B = allocate_matrix(n);
        int **C_recursive = allocate_matrix(n);
        int **C_strassen = allocate_matrix(n);

        initialize_matrix(A, n);
        initialize_matrix(B, n);

        struct timespec start_time, end_time;

        // Measure execution time for recursive_matrix_multiplication
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        recursive_matrix_multiplication(A, B, C_recursive, 0, 0, 0, 0, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double recursive_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

        // Measure execution time for strassen_matrix_multiplication
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        strassen_matrix_multiplication(A, B, C_strassen, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double strassen_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

        printf("%d, %.10f, %.10f\n", n, recursive_time, strassen_time);

        free_matrix(A, n);
        free_matrix(B, n);
        free_matrix(C_recursive, n);
        free_matrix(C_strassen, n);

        n *= 2; // Double the size of the matrix for the next iteration
    }

    return 0;
}

