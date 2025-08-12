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
/*  int arr[] = {7,4,2,3,1,5,8,6};
    int left = 0;
    int right = 7;
    0 < 7; mid = 7/2 + 0 = 3;
    mergeSort(arr[], 0, 3)
    {
        0 < 3; mid = 3/2 + 0 = 1;
        mergeSort(arr[], 0, 1){
            0 < 1; mid = 0;
            mergeSort(arr[], 0, 0){}
            mergeSort(arr[], 2, 1){}
            merge(arr[] {7,4,2,3,1,5,8,6}, 0, 0, 1){
                n1 = 0 - 0 + 1 = 1;
                n2 = 1 - 0 = 1;
                L[0] = arr[0] = 7;
                R[0] = arr[1] = 4;
                after loop: {4,7,2,3,1,5,8,6};
            }
        }
        mergeSort(arr[], 2, 3){
            2 < 3; mid = 1/2 + 2 = 2;
            mergeSort(arr[], 2, 2){}
            mergeSort(arr[], 3, 3){}
            merge(arr[] {4,7,2,3,1,5,8,6}, 2, 2, 3){
                n1 = 1; n2 = 1;
                L[0] = arr[2] = 2;
                R[0] = arr[3] = 3;
                after loop: {4,7,2,3,1,5,8,6};
            }
        }
        merge(arr[] {4,7,2,3,1,5,8,6}, 0, 1, 3){
            n1 = 2; n2 = 2;
            L[0] = arr[0] = 4;
            L[1] = arr[1] = 7;
            R[0] = arr[2] = 2;
            R[1] = arr[3] = 3;
            after loop: {2,3,4,7,1,5,8,6};
        }
    }
    mergeSort(arr[], 4, 7)
    {
        ...
    }



    
*/



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