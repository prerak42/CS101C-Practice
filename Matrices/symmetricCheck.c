#include<stdio.h>
int rows, cols;
void inputMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void isSymmetric(int rows, int cols, int matrix[rows][cols]);

int main(){
    printf("Enter number of rows and columns: \n");
    scanf("%d %d", &rows, &cols);

    if(rows != cols) {
        printf("Matrix must be square to check for symmetry.\n");
        return 1;
    }

    int matrix[rows][cols];

    printf("Enter elements of the matrix:\n");
    inputMatrix(rows, cols, matrix);

    printf("The matrix to be checked for symmetryis:\n");
    printMatrix(rows, cols, matrix);
    
    isSymmetric(rows, cols, matrix);

    return 0;
}

void isSymmetric(int rows, int cols, int matrix[rows][cols]) {
    int symmetric = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }
    if(symmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
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