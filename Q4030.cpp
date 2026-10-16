/*4030. Check ASCII Palindrome*/

/*
You are given a string s consisting of lowercase English letters.

Construct a binary string by replacing each character in s with the 8-bit binary representation of its ASCII value, including leading zeros, while preserving the original order of the characters.

Return true if the resulting binary string is a palindrome. Otherwise, return false.

Example 1:
Input: s = "ff"
Output: true
Explanation:
The ASCII value of f is 102, whose 8-bit binary representation is 01100110.
Thus, the binary string is 0110011001100110.
Since this binary string is a palindrome, the output is true.

Example 2:
Input: s = "leet"
Output: false
Explanation:
The ASCII values of l, e, e, and t are 108, 101, 101, and 116, respectively.
Their 8-bit binary representations are 01101100, 01100101, 01100101, and 01110100.
Thus, the binary string is 01101100011001010110010101110100.
Since this binary string is not a palindrome, the output is false.

Constraints:
1 <= s.length <= 100
s consists of lowercase English letters.
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
#include<bitset>
using namespace std;
#define ll long long int
class Solution {
public:
    bool isPalindromic(string s) {
        string arr="";
        for(char ch:s){
            arr+=bitset<8>(ch).to_string();
        }
        int n=arr.size();
        for(int i=0;i<n/2;i++){
            if(arr[i]!=arr[n-1-i]){
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution sol;
    bool ans=sol.isPalindromic(s);
    cout<<boolalpha<<ans;
    return 0;
}