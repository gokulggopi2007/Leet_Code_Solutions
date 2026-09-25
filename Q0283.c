/*283. Mova Zeroes*/

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 

Constraints:
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
 
*/
#include<stdio.h>
#include<stdlib.h>
void moveZeroes(int* nums, int numsSize) {
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-i-1;j++){
            if(nums[j]==0){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    return ;
}
int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    moveZeroes(nums,numsSize);
    for(int i=0;i<numsSize;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}