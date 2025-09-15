//
// Created by Prerak on 16/9/2025.
//

#include<stdio.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int* arr, int n) {
    for (int l = 0; l < n - 1; l++) {
        for (int m = 0; m < n - l - 1; m++) {
            if (arr[m] > arr[m + 1]) {
                swap(arr, m, m + 1);
            }
        }
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

    n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {   
        printf("%d ", arr[i]);
    }
}