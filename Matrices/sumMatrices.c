#include<stdio.h>
int rows, cols;
void sumMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]);
void inputMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    printf("Enter number of rows and columns: \n");
    scanf("%d %d", &rows, &cols);

    int mat1[rows][cols], mat2[rows][cols], result[rows][cols];

    printf("Enter elements of first matrix:\n");
    inputMatrix(rows, cols, mat1);

    printf("Enter elements of second matrix:\n");
    inputMatrix(rows, cols, mat2);

    printMatrix(rows, cols, mat1);
    printf("+\n");
    printMatrix(rows, cols, mat2);
    printf("=\n");

    sumMatrices(rows, cols, mat1, mat2, result);

    printf("Resultant matrix after addition:\n");
    printMatrix(rows, cols, result);

    return 0;
}

void sumMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
