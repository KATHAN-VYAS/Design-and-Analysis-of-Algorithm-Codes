#include <stdio.h>

// Function to add two matrices
void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen algorithm
void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    // We divide the original matrix into halves
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    // Answer matrix into halves
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    // 7 multiplication mayrix that we will obtain
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half], M5[half][half], M6[half][half], M7[half][half];
    // This temp matrices are needed as a intermediate
    int temp1[half][half], temp2[half][half];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Compute M1 = (A11 + A22) * (B11 + B22)
    add(half, A11, A22, temp1);
    add(half, B11, B22, temp2);
    strassen(half, temp1, temp2, M1);

    // Compute M2 = (A21 + A22) * B11
    add(half, A21, A22, temp1);
    strassen(half, temp1, B11, M2);

    // Compute M3 = A11 * (B12 - B22)
    subtract(half, B12, B22, temp1);
    strassen(half, A11, temp1, M3);

    // Compute M4 = A22 * (B21 - B11)
    subtract(half, B21, B11, temp1);
    strassen(half, A22, temp1, M4);

    // Compute M5 = (A11 + A12) * B22
    add(half, A11, A12, temp1);
    strassen(half, temp1, B22, M5);

    // Compute M6 = (A21 - A11) * (B11 + B12)
    subtract(half, A21, A11, temp1);
    add(half, B11, B12, temp2);
    strassen(half, temp1, temp2, M6);

    // Compute M7 = (A12 - A22) * (B21 + B22)
    subtract(half, A12, A22, temp1);
    add(half, B21, B22, temp2);
    strassen(half, temp1, temp2, M7);

    // Compute C11 = M1 + M4 - M5 + M7
    add(half, M1, M4, temp1);
    subtract(half, temp1, M5, temp2);
    add(half, temp2, M7, C11);

    // Compute C12 = M3 + M5
    add(half, M3, M5, C12);

    // Compute C21 = M2 + M4
    add(half, M2, M4, C21);

    // Compute C22 = M1 - M2 + M3 + M6
    subtract(half, M1, M2, temp1);
    add(half, temp1, M3, temp2);
    add(half, temp2, M6, C22);

    // Combine submatrices to form matrix C
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of square matrices (nxn): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Matrix C (Result of A x B):\n");
    printMatrix(n, C);

    return 0;
}
