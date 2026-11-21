/*367. Valid Perfect Square*/

/*
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.


Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 

Constraints:
1 <= num <= 2^31 - 1
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
bool isPerfectSquare(int num) {
    int g=0;
    if(num==1){
        return true;
    }
    else{
        for(long int i=1;i*i<=num;i++){
            if(i*i==num){
                g=1;
                break;
            }
        }
        if(g==1){
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    bool x=isPerfectSquare(num);
    printf("%s",x?"true":"false");
    return 0;
}
