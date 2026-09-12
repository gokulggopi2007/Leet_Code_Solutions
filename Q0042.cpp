/*42. Trapping Rain Water*/

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

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
#include<string>
using namespace std;
#define ll long long int 
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size()),right(height.size());
        left[0]=height[0];
        right[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++){
             left[i]=max(left[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;i--){
             right[i]=max(right[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            sum+=min(left[i],right[i])-height[i];
        }
        return sum;
    }

};
int main()
{
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    Solution s;
    cout<<s.trap(height)<<endl;
    return 0;
}