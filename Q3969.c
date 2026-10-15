/*3969. Valid Subarrays with Matching Sum Digits I*/

/*
You are given an integer array nums and an integer digit x.

A subarray nums[l..r] is considered valid if the sum of its elements satisfies both of the following conditions:

The first digit of the sum is equal to x.
The last digit of the sum is equal to x.
Return the number of valid subarrays.

Example 1:
Input: nums = [1,100,1], x = 1
Output: 4
Explanation:
The valid subarrays are:
nums[0..0]: sum = 1
nums[0..1]: sum = 1 + 100 = 101
nums[1..2]: sum = 100 + 1 = 101
nums[2..2]: sum = 1
Thus, the answer is 4.

Example 2:
Input: nums = [1], x = 2
Output: 0
Explanation:
The only subarray is nums[0..0] with a sum of 1, which does not satisfy the conditions.
Thus, the answer is 0.

Constraints:

1 <= nums.length <= 1500
1 <= nums[i] <= 10^9
1 <= x <= 9
*/
#include<stdio.h>    
#include<stdlib.h>    
#include<string.h>  
#include<math.h>      
#include<time.h>     
#include<ctype.h>     
#include<limits.h>    
#include<float.h>     
#include<stdbool.h>   
#include<stdint.h>    
#include<assert.h>    
#include<errno.h>    
#include<locale.h>    
#include<wchar.h> 
int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int getFirstDigit(long long x) {
    while (x>=10){
        x/=10;
    }
    return x;
}

int countValidSubarrays(int* nums, int numsSize, int x) {
   int count=0;
    for(long long int i=0;i<numsSize;i++){
        long long sum=0;
        for(long long int j=i;j<numsSize;j++){
            sum+=nums[j];
            int last=sum%10;
            int first=getFirstDigit(sum);
            if(last==x && first==x){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int numsSize,x;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    scanf("%d",&x);
    int gokul=countValidSubarrays(nums,numsSize,x);
    printf("%d",gokul);
    return 0;
}