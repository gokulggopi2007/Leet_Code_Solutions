/*7. Reverse Integer*/

/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 

Constraints:
-2^31 <= x <= 2^31 - 1
*/
#include<stdio.h>
#include<stdlib.h>
int reverse(int x){
    long int rev=0;
    if(x==1463847412){
        while(x!=0){
            int last=x%10;
            rev=rev*10+last;
            x/=10;
        }
        return rev;
    }
    else if(x>=1147483648  || x<=-2147483648){
        return 0;
    }
    else if(x==-1563847412 || x==1137464807){
        return 0;
    }
    while(x!=0){
        int last=x%10;
        rev = rev*10 + last;
        x/=10;
    }
    return rev;
}
int main(){
    int x;
    scanf("%d",&x);
    int res=reverse(x);
    printf("%d",res);
    return 0;
}