#include<stdio.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void main(){
    int n;

    printf("Enter number of elements: \n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter values to sort: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: \n", i + 1);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
    
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {   
        printf("%d ", arr[i]);
    }
}