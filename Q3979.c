/*3979. maximum Valid Pair Sum*/

/*
You are given an integer array nums of length n and an integer k.

A pair of indices (i, j) is called valid if:

0 <= i < j < n
j - i >= k
Return the maximum value of nums[i] + nums[j] among all valid pairs.


Example 1:
Input: nums = [1,3,5,2,8], k = 2
Output: 13
Explanation:
The valid pairs are:
(0, 2): nums[0] + nums[2] = 6
(0, 3): nums[0] + nums[3] = 3
(0, 4): nums[0] + nums[4] = 9
(1, 3): nums[1] + nums[3] = 5
(1, 4): nums[1] + nums[4] = 11
(2, 4): nums[2] + nums[4] = 13
Thus, the answer is 13.​​​​​​​

Example 2:
Input: nums = [5,1,9], k = 1
Output: 14
Explanation:
Since k = 1, every pair is valid.
The maximum value is obtained from a pair (0, 2)​​​​​​​, which is nums[0] + nums[2] = 5 + 9 = 14.
Thus, the answer is 14.
 

Constraints:
2 <= n == nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= n - 1
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
int maxValidPairSum(int* nums, int numsSize, int k) {
    int l=nums[0];
    int num=INT_MIN;
    for(int j=k;j<numsSize;j++){
        if(nums[j-k]>l){
            l=nums[j-k];
        }
        if(l+nums[j]>num){
            num=l+nums[j];
        }
    }
    return num;
}
int main()
{
    int numsSize,k;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    scanf("%d",&k);
    printf("%d",maxValidPairSum(nums,numsSize,k));
    return 0;
}