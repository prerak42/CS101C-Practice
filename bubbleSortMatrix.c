#include <stdio.h>
int a, b;
void swap(int arr[], int i, int j);
void bubbleSortColumn(int arr[a][b], int rows, int colIndex);
void bubbleSortRow(int arr[a][b], int cols, int rowIndex);
void inputMatrix(int arr[a][b], int rows, int cols);
void printMatrix(int arr[a][b], int rows, int cols);

int main() {
    printf("Enter number of rows: \n");
    scanf("%d", &a);
    printf("Enter number of columns: \n");
    scanf("%d", &b);

    int matrix[a][b];

    inputMatrix(matrix, a, b);

    printf("Original Matrix: \n");
    printMatrix(matrix, a, b);

    // Sort each row
    for (int i = 0; i < a; i++) {
        bubbleSortRow(matrix, b, i);
    }

    // Sort each column
    for (int j = 0; j < b; j++) {
        bubbleSortColumn(matrix, a, j);
    }

    printf("Sorted Matrix: \n");
    printMatrix(matrix, a, b);

    return 0;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSortRow(int arr[a][b], int cols, int rowIndex) {
    for (int l = 0; l < cols - 1; l++) {
        for (int m = 0; m < cols - l - 1; m++) {
            if (arr[rowIndex][m] > arr[rowIndex][m + 1]) {
                swap(arr[rowIndex], m, m + 1);
            }
        }
    }
}

void bubbleSortColumn(int arr[a][b], int rows, int colIndex) {
    for (int l = 0; l < rows - 1; l++) {
        for (int m = 0; m < rows - l - 1; m++) {
            if (arr[m][colIndex] > arr[m + 1][colIndex]) {
                swap(arr[m], m, m + 1);
            }
        }
    }
}

void inputMatrix(int arr[a][b], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: \n", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int arr[a][b], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}