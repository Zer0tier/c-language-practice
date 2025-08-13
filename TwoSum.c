#include<stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* returnArray = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;


    for(int i = 0; i < numsSize; i++){
        for(int j = numsSize - 1; j > i; j--){
            if(nums[i]+nums[j]==target){
                returnArray[0] = i;
                returnArray[1] = j;
            }
        }
    }

 
    return returnArray;
    free(returnArray);
}

int main(){
    int nums[] = {2,7,11,15};
    int numsSize = 4;
    int target = 9;
    int returnSize = 2;

    int* returnArray = twoSum(nums,numsSize,target,&returnSize);
    for (int i = 0; i < returnSize; i++) {
     printf("%d\n", returnArray[i]);
    }
}