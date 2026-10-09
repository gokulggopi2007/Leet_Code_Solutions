/*3931. Check Adjacent Digit Differences*/

/*
You are given a string s consisting of digits.

Return true if the absolute difference between every pair of adjacent digits is at most 2, otherwise return false.

The absolute difference between a and b is defined as abs(a - b).

Example 1:
Input: s = "132"
Output: true
Explanation:
The absolute difference between digits at s[0] and s[1] is abs(1 - 3) = 2.
The absolute difference between digits at s[1] and s[2] is abs(3 - 2) = 1.
Since both differences are at most 2, the answer is true.

Example 2:
Input: s = "129"
Output: false
Explanation:
The absolute difference between digits at s[0] and s[1] is abs(1 - 2) = 1.
The absolute difference between digits at s[1] and s[2] is abs(2 - 9) = 7, which is greater than 2.
Therefore, the answer is false.

Constraints:
2 <= s.length <= 100
s consists only of digits.
*/
#include<stdio.h>    
#include<stdlib.h>    
#include<string.h>  
#include<math.h>      
#include<time.h>     
#include<ctype.h>     
#include<limits.h>    
#include<float.h>     
#include<stdbool.h>   
#include<stdint.h>    
#include<assert.h>    
#include<errno.h>    
#include<locale.h>    
#include<wchar.h> 
bool isAdjacentDiffAtMostTwo(char* s) {
    for(int i=0;i<strlen(s)-1;i++){
        int num1=s[i]-'0';
        int num2=s[i+1]-'0';
        if(abs(num1-num2)>2){
            return false;
        }
    }
    return true;
}
int main()
{
    char s[101];
    scanf("%s",s);
    if(isAdjacentDiffAtMostTwo(s)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}