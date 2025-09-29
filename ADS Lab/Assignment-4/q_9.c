#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

int main() {
    Matrix m;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m.rows, &m.cols);

    // Allocate memory for rows pointers
    m.matrix = (int **)malloc(m.rows * sizeof(int*));
    for(int i = 0; i < m.rows; i++) {
        m.matrix[i] = (int *)malloc(m.cols * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            scanf("%d", &m.matrix[i][j]);
        }
    }

    printf("Matrix is:\n");
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            printf("%d ", m.matrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for(int i = 0; i < m.rows; i++) {
        free(m.matrix[i]);
    }
    free(m.matrix);

    return 0;
}
