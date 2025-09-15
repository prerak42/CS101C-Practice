#include<stdio.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int* arr, int n) {
    for (int l = 0; l < n - 1; l++) {
        int minIndex = l;
        for (int m = l + 1; m < n; m++) {
            if (arr[m] < arr[minIndex]) {
                minIndex = m;
            }
        }
        swap(arr, l, minIndex);
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

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {   
        printf("%d ", arr[i]);
    }
}