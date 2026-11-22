/*371. Sum of Two Integets*/

/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5
 

Constraints:
-1000 <= a, b <= 1000
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
int getSum(int a, int b) {
  return a+b;  
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",getSum(a,b));
    return 0;
}