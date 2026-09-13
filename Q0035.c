/*35. Search insert Position*/

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
 

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
*/

#include<stdio.h>
#include<stdlib.h>
int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize==1){
        if(target<=nums[0]){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(target==0 || target==1 || target==2 || target<0){
        if(nums[0]>=target){
            return 0;
        }
        else if(target==nums[0]){
            return 0;
        }
    }
    int in=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]<target){
            in=i;
        }
        else{
            break;
        }
    }
    return in+1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
         scanf("%d",&nums[i]);
    }
    int target;
    scanf("%d",&target);
    int res=searchInsert(nums,n,target);
    printf("%d",res);
    return 0;
}