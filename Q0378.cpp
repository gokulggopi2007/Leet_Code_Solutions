/*378. kth Smallest Element in a Sorted Matrix*/

/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n^2
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<>> gokul;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                gokul.push(matrix[i][j]);
            }
        }
        while(k!=1){
            gokul.pop();
            k--;
        }
        return gokul.top();
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int k;
    cin>>k;
    Solution s;
    cout<<s.kthSmallest(matrix,k)<<endl;
    return 0;
}