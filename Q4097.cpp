/*4097. Mininmum Value of Merged Integers*/

/*
You are given an integer array nums of even length n.

You have to merge the elements of nums in pairs by merging nums[0] with nums[1], nums[2] with nums[3], and so on, until nums[n - 2] with nums[n - 1].

Return the minimum value among all the resulting merged integers.

To merge two integers, concatenate all the decimal digits of the first integer followed by all the decimal digits of the second integer.

Example 1:
Input: nums= [23,55,42,21]
Output: 2355
Explanation:
Merging nums[0] = 23 and nums[1] = 55 gives 2355.
Merging nums[2] = 42 and nums[3] = 21 gives 4221.
The minimum value among the merged numbers is min(2355, 4221) = 2355.

Example 2:
Input: nums = [34,7,11,11]
Output: 347
Explanation:
Merging nums[0] = 34 and nums[1] = 7 gives 347.
Merging nums[2] = 11 and nums[3] = 11 gives 1111.
The minimum value among the merged numbers is min(347, 1111) = 347.

Example 3:
Input: nums = [9,20]
Output: 920
Explanation:
Merging nums[0] = 9 and nums[1] = 20 gives 920.
There is only one merged number, so the minimum value is 920.
 
Constraints:
2 <= n == nums.length <= 100
n is even
1 <= nums[i] <= 1000
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
    int minMergedInteger(vector<int>& nums) {
       int min=INT_MAX;
        vector<int> arr;
        for(int i=0;i<nums.size()-1;i+=2){
            int temp=nums[i],count=0,num=0;
            if(nums[i+1]>=1 && nums[i+1]<=9){
                num=temp*10+nums[i+1];
            }
            else if(nums[i+1]>=10 && nums[i+1]<=99){
                num=temp*100+nums[i+1];
            }
            else if(nums[i+1]>=100 && nums[i+1]<=999){
                num=temp*1000+nums[i+1];
            }
            else if(nums[i+1]==1000){
                num=temp*10000+nums[i+1];
            }
            arr.push_back(num);
        }
        if(arr.size()==1){
            return arr[0];
        }
        return *min_element(arr.begin(),arr.end());
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
    cout<<s.minMergedInteger(nums)<<endl;
    return 0;
}