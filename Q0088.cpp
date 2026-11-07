/*88. Merge Sorted Array*/

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10^9 <= nums1[i], nums2[j] <= 10^9
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[x++];
        }
        sort(nums1.begin(),nums1.end());
        return;
    }
};
int main()
{
    int num1,num2;
    cin>>num1>>num2;
    vector<int> nums1(num1);
    for(int i=0;i<num1;i++){
        cin>>nums1[i];
    }
    vector<int> nums2(num2);
    for(int i=0;i<num2;i++){
        cin>>nums2[i];
    }
    int m,n;
    cin>>m>>n;
    Solution s;
    s.merge(nums1,m,nums2,n);
    for(int x:nums1){
        cout<<x<<" ";
    }
    return 0;
}