/*3921. Score Validator*/

/*
You are given a string array events.

Initially, score = 0 and counter = 0. Each element in events is one of the following:

"0", "1", "2", "3", "4", "6": Add that value to the total score.
"W": Increase the counter by 1. No score is added.
"WD": Add 1 to the total score.
"NB": Add 1 to the total score.
Process the array from left to right. Stop processing when either:

All elements in events have been processed, or
The counter becomes 10.
Return an integer array [score, counter], where:

score is the final total score.
counter is the final counter value.
 

Example 1:

Input: events = ["1","4","W","6","WD"]

Output: [12,1]

Explanation:

Event	Score	Counter
"1"	1	0
"4"	5	0
"W"	5	1
"6"	11	1
"WD"	12	1
Final result: [12, 1].

Example 2:

Input: events = ["WD","NB","0","4","4"]

Output: [10,0]

Explanation:

Event	Score	Counter
"WD"	1	0
"NB"	2	0
"0"	2	0
"4"	6	0
"4"	10	0
Final result: [10, 0].

Example 3:

Input: events = ["W","W","W","W","W","W","W","W","W","W","W"]

Output: [0,10]

Explanation:

After 10 occurrences of "W", the counter reaches 10, so processing stops. The remaining events are ignored.

 

Constraints:
1 <= events.length <= 1000
events[i] is one of "0", "1", "2", "3", "4", "6", "W", "WD", or "NB".
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
    vector<int> scoreValidator(vector<string>& a) {
        int s=0,c=0;
        for(size_t i=0;i<a.size() && c<10;++i) {
            if(a[i]=="WD"||a[i]=="NB") ++s;
            else if(a[i]=="W") ++c;
            else s+=a[i][0]-'0';
        }

        return {s,c};
    }
};
int main()
{
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution s;
    vector<int> ans=s.scoreValidator(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}