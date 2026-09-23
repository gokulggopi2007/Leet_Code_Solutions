/*77. Combinations*/

/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:
1 <= n <= 20
1 <= k <= n
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
    int pcnt(int num){
        int oc=0;
        while(num!=0){
            oc++;
            num=num&(num-1);
        }
        return oc;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int ctr=(1<<k)-1;ctr<(1<<n);ctr++){
            int oc=pcnt(ctr);
            if(oc==k){
                vector<int> combo;
                for(int sh=0;sh<n;sh++){
                    if((ctr&(1<<sh))){
                        combo.push_back(sh+1);
                    }
                }
                ans.push_back(combo);
            }
        } 
        return ans;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    Solution s;
    vector<vector<int>> ans=s.combine(n,k);
    for(auto combo:ans){
        for(int i=0;i<combo.size();i++){
            cout<<combo[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}