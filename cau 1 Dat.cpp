#include <stdio.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {
       
        if (arr[j] < pivot) {
            i++;   
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1); 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Nhap vao so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap vao cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

  
    quickSort(arr, 0, n - 1);

 
    printf("Mang sau khi sap xep theo thu tu tang dan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
















































