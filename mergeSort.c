#include<stdio.h>
#include <stdlib.h>

//arr = 7,4,2,3,1,5,8,6

void merge(int arr[], int left, int mid, int right){
    int i,j,k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for(int i =0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j =0; j < n2; j++){
        R[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
           arr[k] = L[i];
           i++; 
        }else{
           arr[k] = R[j];
           j++;
        }
        k++;
    }


    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (right - left) / 2 + left;

        mergeSort(arr, left , mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}



int main() {
    int arr[] = {7,4,2,3,1,5,8,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}