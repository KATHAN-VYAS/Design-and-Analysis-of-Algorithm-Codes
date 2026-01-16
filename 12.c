#include<stdio.h>
#include<stdbool.h>

// Set 1 as position of queen

void create_matrix(int size, char matrix[size][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = '-';
        }
    }
}

void print_matrix(int size, char matrix[size][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
int count_Q(int size, char matrix[size][size])
{
    int count;
    for(int i =0; i <size; i++)
    {
        for (int j =0; j<size; j++)
        {
            if(matrix[i][j]=='Q')
            {
                count++;
            }
        }
    }
    return count;
}
bool is_safe(int size, char matrix[size][size], int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (matrix[row][i] == 'Q')
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (matrix[i][j] == 'Q')
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < size; i++, j--)
        if (matrix[i][j] == 'Q')
            return false;

    return true;
}

bool Q_position(int size, char matrix[size][size], int col) {
    if (col >= size)
        return true;

    for(int i = 0; i < size; i++) {
        if (is_safe(size, matrix, i, col)) {
            matrix[i][col] = 'Q';

            if(Q_position(size, matrix, col + 1))
                return true;

            matrix[i][col] = '-'; // Backtracking from here
        }
    }

    return false;
}

int main() {
    int size;
    printf("Enter size of matrix: ");
    scanf("%d", &size);

    if (size < 4) {
        printf("no solution\n");
        return 0;
    }

    char matrix[size][size];
    create_matrix(size, matrix);

    if (Q_position(size, matrix, 0))
        print_matrix(size, matrix);
    else
        printf("no solution\n");

    return 0;
}