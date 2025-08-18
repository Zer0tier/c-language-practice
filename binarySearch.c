/*
Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/
#include<stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0; 
    int right = numsSize -1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return mid;
        }if(nums[mid] < target){
            left++;
        }else{
            right--;
        }
    }

    return -1;
}

int main(){
    int nums[] = {-1,0,3,5,9,12};
    int target = 2;
    int numsSize = 6;

    printf("%d\n",search(nums,numsSize,target));

    return 0;
}