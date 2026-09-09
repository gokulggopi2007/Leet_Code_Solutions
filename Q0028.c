/*28. Find the Index of the First Occurrence in a String */

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int strStr(char* haystack, char* needle) {
    int n=strlen(haystack);
    int m=strlen(needle);
    if(m==0){
        return 0;
    } 
    if(n<m){
        return -1;
    } 
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(haystack[i + j]!=needle[j]) {
                break;
            }
        }
        if(j==m){  
            return i;
        }
    }
    return -1;

}
int main()
{
    char haystack[1000],needle[1000];
    scanf("%s %s",haystack,needle);
    printf("%d",strStr(haystack,needle));
    return 0;
}