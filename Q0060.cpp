/*60. Permutation Sequence*/

/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"

Example 3:
Input: n = 3, k = 1
Output: "123"
 
Constraints:
1 <= n <= 9
1 <= k <= n!
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
    string getPermutation(int n, int k) {
        string ans="";
        int fact=1;
        vector<int> arr;
        for(int i=1;i<n;i++){
            fact*=i;
            arr.push_back(i);
        }
        arr.push_back(n);
        k--;
        while(!arr.empty()){
            int i=k/fact;
            ans.push_back(arr[i]+'0');
            arr.erase(arr.begin()+i);
            if(arr.size()==0){
                break;
            }
            k=k%fact;
            fact/=arr.size();
        }
        return ans;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    Solution s;
    string ans=s.getPermutation(n,k);
    cout<<ans<<endl;
    return 0;
}