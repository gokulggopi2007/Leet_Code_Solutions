/*3941. Password Strength*/

/*
You are given a string password.

The strength of the password is calculated based on the following rules:

1 point for each distinct lowercase letter ('a' to 'z').
2 points for each distinct uppercase letter ('A' to 'Z').
3 points for each distinct digit ('0' to '9').
5 points for each distinct special character from the set "!@#$".
Each character contributes at most once, even if it appears multiple times.

Return an integer denoting the strength of the password.

Example 1:
Input: password = "aA1!"
Output: 11
Explanation:
The distinct characters are 'a', 'A', '1' and '!'.
Thus, the strength = 1 + 2 + 3 + 5 = 11.

Example 2:
Input: password = "bbB11#"
Output: 11
Explanation:
The distinct characters are 'b', 'B', '1' and '#'.
Thus, the strength = 1 + 2 + 3 + 5 = 11.​​​​​​​
 

Constraints:
1 <= password.length <= 10^5
password consists of lowercase and uppercase English letters, digits, and special characters from "!@#$".
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
    int passwordStrength(string password) {
        int sum=0;
        sort(password.begin(),password.end());
        password.erase(unique(password.begin(),password.end()),password.end());
        for(char ch:password){
            if(ch>='a' && ch<='z') sum+=1;
            else if(ch>='A' && ch<='Z') sum+=2;
            else if(ch>='0' && ch<='9') sum+=3;
            else if(ch=='!' || ch=='@' || ch=='#' || ch=='$') sum+=5;
        }
        return sum;
    }
};
int main()
{
    string password;
    cin>>password;
    Solution s;
    cout<<s.passwordStrength(password)<<endl;
    return 0;
}