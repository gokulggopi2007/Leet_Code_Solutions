/*41. First Missing Positive */

/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.


Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:
1 <= nums.length <= 105
-2^31 <= nums[i] <= 2^31 - 1

*/

#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<iomanip>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
using namespace std;
#define ll long long int 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int pre[100002];
        for(int i=0;i<100002;i++){
            pre[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0 || nums[i]>100001){
                continue;
            }
            else{
                pre[nums[i]]=1;
            }
        }
        for(int i=1;i<100002;i++){
            if(pre[i]==0){
                return i;
            }
        }
        return 0;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}
