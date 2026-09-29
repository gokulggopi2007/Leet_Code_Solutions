/*169. Majority Element*/

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.
*/
#include<stdio.h>
#include<stdlib.h>
int majorityElement(int* nums, int numsSize) {
    int j=0,count=0;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            j=nums[i];
        }
        if(j==nums[i]){
            count++;
        }
        else{
            count--;
        }
    }
    return j;
}
int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    int num=majorityElement(nums,numsSize);
    printf("%d",num);
    return 0;
}