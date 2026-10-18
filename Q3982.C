/*3982. Sum of Integers with Maximum Digit Range*/

/*
You are given an integer array nums.

The digit range of an integer is defined as the difference between its largest digit and smallest digit.

For example, the digit range of 5724 is 7 - 2 = 5.

Return the sum of all integers in nums whose digit range is equal to the maximum digit range among all integers in the array.

Example 1:
Input: nums = [5724,111,350]
Output: 6074
Explanation:
i	nums[i]	Largest	Smallest	Digit Range
0	5724	7	2	5
1	111	1	1	0
2	350	5	0	5
The maximum digit range is 5. The integers with this digit range are 5724 and 350, so the answer is 5724 + 350 = 6074.

Example 2:
Input: nums = [90,900]
Output: 990
Explanation:
i	nums[i]	Largest	Smallest	Digit Range
0	90	9	0	9
1	900	9	0	9
The maximum digit range is 9. Both integers have this digit range, so the answer is 90 + 900 = 990.

Constraints:
1 <= nums.length <= 100
10 <= nums[i] <= 10^5
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
int maxDigitRange(int* nums, int numsSize) {
    int sum=0;
    int *arr=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        int max=0,min=9;
        int temp=nums[i];
        while(temp!=0){
            int last=temp%10;
            if(last>max){
                max=last;
            }
            if(last<min){
                min=last;
            }
            temp/=10;
        }
        arr[i]=abs(max-min);
    }
    int num=0;
    for(int i=0;i<numsSize;i++){
        if(arr[i]>num){
            num=arr[i];
        }
    }
    for(int i=0;i<numsSize;i++){
        if(arr[i]==num){
            sum+=nums[i];
        }
    }
    free(arr);
    return sum;
}
int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    printf("%d",maxDigitRange(nums,numsSize));
    return 0;
}