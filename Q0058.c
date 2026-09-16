/*58. Length of last Word*/

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 10^4
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lengthOfLastWord(char* s) {
    int count=0,len=strlen(s);
    while(len>=0 && s[len-1]==' '){
        len--;
    }
    for(int i=len-1;i>=0;i--){
        if(s[i]!=' '){
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
int main()
{
    char s[100000];
    scanf("%[^\n]",s);
    int num=lengthOfLastWord(s);
    printf("%d",num);
    return 0;
}