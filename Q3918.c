/*3918. Sum of Primes Between Number and Its Reverse*/

/*
You are given an integer n.

Let r be the integer formed by reversing the digits of n.

Return the sum of all prime numbers between min(n, r) and max(n, r), inclusive.

Example 1:
Input: n = 13
Output: 132
Explanation:
The reverse of 13 is 31. Thus, the range is [13, 31].
The prime numbers in this range are 13, 17, 19, 23, 29, and 31.
The sum of these prime numbers is 13 + 17 + 19 + 23 + 29 + 31 = 132.

Example 2:
Input: n = 10
Output: 17
Explanation:
The reverse of 10 is 1. Thus, the range is [1, 10].
The prime numbers in this range are 2, 3, 5, and 7.
The sum of these prime numbers is 2 + 3 + 5 + 7 = 17.

Example 3:
Input: n = 8
Output: 0
Explanation:
The reverse of 8 is 8. Thus, the range is [8, 8].
There are no prime numbers in this range, so the sum is 0.
 

Constraints:
1 <= n <= 1000
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
int sumOfPrimesInRange(int n) {
   int num=n,sum=0,rev=0;
   while(num!=0){
       rev=rev*10+num%10;
       num/=10;
   } 
   int d=(rev<n)?rev:n;
   int y=(rev>n)?rev:n;
   for(int i=d;i<=y;i++){
    int count=0;
    for(int j=1;j<=i;j++){
        if(i%j==0){
            count++;
        }
    }
    if(count==2){
        sum+=i;
    }
   }
   return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",sumOfPrimesInRange(n));
    return 0;
}