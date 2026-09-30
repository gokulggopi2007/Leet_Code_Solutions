/*164. Maximum Gap*/

/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int gokul(void const *a, void const *b){
    return *(int*)a-*(int*)b;
}

int maximumGap(int* nums, int numsSize) {
    if(numsSize==1){
        return 0;
    }
    qsort(nums,numsSize,sizeof(int),gokul);
    int max=INT_MIN;
    for(int i=0;i<numsSize-1;i++){
        if(max<abs(nums[i]-nums[i+1])){
            max=abs(nums[i]-nums[i+1]);
        }
    }
    return max;
}
int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    int x=maximumGap(nums,numsSize);
    printf("%d",x);
    return 0;
}