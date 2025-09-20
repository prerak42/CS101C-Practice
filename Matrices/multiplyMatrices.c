#include<stdio.h>
int rows, cols, rows1, cols1, rows2, cols2;
void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]);
void inputMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    printf("Enter number of rows and columns for first matrix: \n");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter number of rows and columns for second matrix: \n");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Error! Number of columns in first matrix must be equal to number of rows in second matrix.\n");
        return 1;
    }

    int mat1[rows1][cols1], mat2[rows2][cols2], result[rows1][cols2];

    printf("Enter elements of first matrix:\n");
    inputMatrix(rows1, cols1, mat1);

    printf("Enter elements of second matrix:\n");
    inputMatrix(rows2, cols2, mat2);

    printMatrix(rows1, cols1, mat1);
    printf("*\n");
    printMatrix(rows2, cols2, mat2);
    printf("=\n");

    multiplyMatrices(rows1, cols1, mat1, rows2, cols2, mat2, result);

    printf("Resultant matrix after multiplication:\n");
    printMatrix(rows1, cols2, result);

    return 0;
}

void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
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