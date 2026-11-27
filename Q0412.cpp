/*412. Fizz Buzz*/

/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 
Constraints:
1 <= n <= 10^4
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
    vector<string> fizzBuzz(int n) {
        vector<string> arr(n);
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                arr[i-1]="FizzBuzz";
            }
            else if(i%3==0){
                arr[i-1]="Fizz";
            }
            else if(i%5==0){
                arr[i-1]="Buzz";
            }
            else{
                arr[i-1]=to_string(i);
            }
        }
        return arr;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<string> ans=s.fizzBuzz(n);
    for(string s:ans){
        cout<<s<<" ";
    }
    return 0;
}