/*3959. Check Good Integer*/

/*
You are given a positive integer n.

Let digitSum be the sum of the digits of n, and let squareSum be the sum of the squares of the digits of n.

An integer is called good if squareSum - digitSum >= 50.

Return true if n is good. Otherwise, return false.

Example 1:
Input: n = 1000
Output: false
Explanation:
The digits of 1000 are 1, 0, 0, and 0.
The digitSum is 1 + 0 + 0 + 0 = 1.
The squareSum is 12 + 02 + 02 + 02 = 1.
The squareSum - digitSum is 1 - 1 = 0. As 0 is not greater than or equal to 50, the output is false.

Example 2:
Input: n = 19
Output: true
Explanation:
The digits of 19 are 1 and 9.
The digitSum is 1 + 9 = 10.
The squareSum is 12 + 92 = 1 + 81 = 82.
The squareSum - digitSum is 82 - 10 = 72. As 72 is greater than or equal to 50, the output is true.
 
Constraints:
1 <= n <= 10^9
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
bool checkGoodInteger(int n) {
    int sum=0,temp=n,sum1=0;
    while(temp!=0){
        sum+=temp%10;
        temp/=10;
    }
    temp=n;
    while(temp!=0){
        int last=temp%10;
        sum1+=pow(last,2);
        temp/=10;
    }
    if((sum1-sum)>=50){
        return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    bool ans=checkGoodInteger(n);
    printf("%s",ans?"true":"false");
    return 0;
}