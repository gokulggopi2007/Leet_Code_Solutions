/*4. Median of Two Sorted Arrays*/

/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6

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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int num=nums1.size()+nums2.size();
    int arr[num];
    for(int i=0;i<nums1.size();i++){
        arr[i]=nums1[i];
    }
    for(int i=0;i<nums2.size();i++){
        arr[nums1.size()+i]=nums2[i];
    }
    sort(arr, arr + num);
    double res;
    if(num%2!=0){
        res=arr[num/2];
    }
    else{
        res=(arr[num/2-1]+arr[num/2])/2.0;
    }
    return res;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    Solution s;
    double result=s.findMedianSortedArrays(nums1,nums2);
    cout<<fixed<<setprecision(5)<<result<<endl;
    return 0;
}