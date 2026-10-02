/*4038. Count Integers Appearing in Single Block*/

/*
You are given an integer array nums.

An integer x is special if all occurrences of x in nums appear in a single contiguous block.

Return the number of distinct special integers in nums.


Example 1:
Input: nums = [1,2,2,1]
Output: 1
Explanation:
1 appears at indices 0 and 3, forming two separate blocks, so it is not special.
2 appears in a single contiguous block at indices [1, 2], so it is special.
Therefore, there is one special integer.

Example 2:
Input: nums = [3,3,1,2,2,1]
Output: 2
Explanation:
3 appears in a single contiguous block at indices [0, 1], so it is special.
1 appears at indices 2 and 5, forming two separate blocks, so it is not special.
2 appears in a single contiguous block at indices [3, 4], so it is special.
Therefore, there are two special integers.

 

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
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
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
#define ll long long int
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        mp[nums[0]]=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                mp[nums[i]]++;
            }
        }
        int cnt=0;
        for(auto &p:mp){
            if(p.second==1){
                cnt++;
            }
        }
        return cnt;
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
    int x=s.countSpecialIntegers(nums);
    cout<<x;
    return 0;
}