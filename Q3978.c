/*3978. Unique Middle Element*/

/*
You are given an integer array nums of odd length n.

Return true if the middle element of nums appears exactly once in the array. Otherwise return false.

Example 1:
Input: nums = [1,2,3]
Output: true
Explanation:
The middle element of nums is 2, which appears exactly once.
Thus, the answer is true.

Example 2:
Input: nums = [1,2,2]
Output: false
Explanation:
The middle element of nums is 2, which appears twice.
Thus, the answer is false.

Constraints:
1 <= n == nums.length <= 100
n is odd.
1 <= nums[i] <= 100
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
bool isMiddleElementUnique(int* nums, int numsSize) {
   int n=numsSize/2;
   for(int i=0;i<numsSize;i++){
       if(n==i){
           continue;
       }
       else{
           if(nums[i]==nums[n]){
               return false;
           }
       }
   }
    return true;
}
int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    bool ans=isMiddleElementUnique(nums,numsSize);
    printf("%s",ans?"true":"false");
    return 0;
}