/*4065. Rearrange Array by Removing Distinct Values*/

/*
You are given an integer array nums.

You start with an empty array ans. Repeat the following operation until nums is empty:

Identify all distinct values currently present in nums.
Remove one occurrence of every distinct value currently in nums, and append those values to ans in ascending order.
Return the array ans.

Example 1:
Input: nums = [3,1,3,2,1,3]
Output: [1,2,3,1,3,3]
Explanation:
Operation	Appended to ans	nums after	ans after
1	1, 2, 3	[3, 1, 3]	[1, 2, 3]
2	1, 3	[3]	[1, 2, 3, 1, 3]
3	3	[]	[1, 2, 3, 1, 3, 3]
nums is now empty, so the answer is [1, 2, 3, 1, 3, 3].

Example 2:
Input: nums = [7,7,4,4,4]
Output: [4,7,4,7,4]
Explanation:
Operation	Appended to ans	nums after	ans after
1	4, 7	[7, 4, 4]	[4, 7]
2	4, 7	[4]	[4, 7, 4, 7]
3	4	[]	[4, 7, 4, 7, 4]
nums is now empty, so the answer is [4, 7, 4, 7, 4].

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
    vector<int> g(vector<int>& arr,vector<int>& gokul){
        int sum=0;
        for(int i=0;i<101;i++){
            sum+=arr[i];
            if(arr[i]!=0){
                gokul.push_back(i);
                arr[i]--;
            }
        }
        if(sum==0){
            return gokul;
        }
        return g(arr,gokul);
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr(101,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        vector<int> gokul;
        return g(arr,gokul);
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
    vector<int> x=s.rearrangeArray(nums);
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    return 0;
}