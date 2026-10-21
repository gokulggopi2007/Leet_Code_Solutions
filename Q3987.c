/*3987. Minimum Total Cost to Process All Elements*/

/*
You are given an integer array nums and an integer k.

Initially, you have k units of resources.

You must process the elements of nums from left to right. To process the ith element, you need nums[i] resources.

If your available resources are less than nums[i], you may perform an operation that increases your available resources by k. The value of k is fixed and does not change throughout the process. The first such operation incurs a cost of 1, the second incurs a cost of 2, and so on.

After processing the ith element, your available resources decrease by nums[i].

Return an integer denoting the minimum total cost required to process all elements. Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: nums = [1,2,3,4], k = 4

Output: 3

Explanation:

After processing nums[0], we have 4 - 1 = 3 units of resources left.
After processing nums[1], we have 3 - 2 = 1 unit of resources left.
Since nums[2] = 3 and only 1 unit of resources is available, we perform the first operation costing 1. After processing nums[2], we have 1 + 4 - 3 = 2 units of resources left.
Since nums[3] = 4 and only 2 units of resources are available, we perform the second operation costing 2, to have 2 + 4 = 6 units of resources, which is enough to process nums[3].
Thus, the total cost is 1 + 2 = 3.
Example 2:

Input: nums = [1,1,7,14], k = 4

Output: 15

Explanation:

After processing nums[0], we have 4 - 1 = 3 units of resources left.
After processing nums[1], we have 3 - 1 = 2 units of resources left.
Since nums[2] = 7 and only 2 units of resources are available, we perform two operations costing 1 + 2 = 3. After processing nums[2], we have 2 + 4 + 4 - 7 = 3 units of resources left.
Since nums[3] = 14 and only 3 units of resources are available, we perform three operations costing 3 + 4 + 5 = 12, to have 3 + 4 + 4 + 4 = 15 units of resources, which is enough to process nums[3].
Thus, the total cost is 3 + 12 = 15.
Example 3:

Input: nums = [1,2,3,4], k = 10

Output: 0

Explanation:

To process all elements, we can use the initial 10 units of resources without performing any operations. Thus, the total cost required is 0.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= 10^9
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
int minimumCost(int* nums, int numsSize, int k) {
    long long MOD =1000000007LL;
    long long resources=k;
    long long ops=0;
    long long cost=0;
    int sovalemrin[100005];
    for(int i=0;i<numsSize;i++){
        sovalemrin[i]=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        long long x=sovalemrin[i];
        if(resources<x){
            long long deficit=x-resources;
            long long m=(deficit+k-1)/k;
            __int128 add_cost=(__int128)m*(2*ops+m+1)/2;
            add_cost%=MOD;
            cost+=add_cost;
            ops+=m;
            resources+=m*(long long)k;
        }
        resources-=x;
    }
    return (int)(cost%MOD);
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
    int ans=minimumCost(nums,numsSize,k);
    printf("%d",ans);
    return 0;
}