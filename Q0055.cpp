/*55. Jump Game*/

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
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
    bool canJump(vector<int>& nums) {
       int maxvalue=0;
       for(int i=0;i<nums.size();i++){
         if(i>maxvalue){
            return false;
         }
         maxvalue=max(maxvalue,i+nums[i]);
       } 
       return true;
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
    bool ans=s.canJump(nums);
    cout<<boolalpha<<ans<<endl;
    return 0;
}