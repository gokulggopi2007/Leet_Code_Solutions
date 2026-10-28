/*118. Pascel's Triangle*/

/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
 

Constraints:
1 <= numRows <= 30
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> gokul;
        for(int i=0;i<numRows;i++){
            vector<int> go(i+1,1);
            for(int j=1;j<i;j++){
               go[j]=gokul[i-1][j-1]+gokul[i-1][j];
            }
            gokul.push_back(go);
        }
        return gokul;
    }
};
int main()
{
    int numRows;
    cin>>numRows;
    Solution s;
    vector<vector<int>> arr=s.generate(numRows);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}