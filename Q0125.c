/*125. Valid Palindrome*/

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>
bool isPalindrome(char* s) {
    int len=strlen(s),count=0;
    char str[len];
    for(int i=0;i<len;i++){
       if(isalnum(s[i])){
        str[count]=tolower(s[i]);
        count++;
       }
    }
    for(int i=0;i<count;i++){
        if(str[i]!=str[count-i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    char s[200001];
    scanf("%[^\n]",s);
    if(isPalindrome(s)){
        printf("true\n");
    } 
    else{
        printf("false\n");
    }
    return 0;
}