/*3945. Digit Frequency Score*/

/*
You are given an integer n.

The score of n is defined as the sum of d * freq(d) over all distinct digits d, where freq(d) denotes the number of times the digit d appears in n.

Return an integer denoting the score of n.

Example 1:
Input: n = 122
Output: 5
Explanation:
The digit 1 appears 1 time, contributing 1 * 1 = 1.
The digit 2 appears 2 times, contributing 2 * 2 = 4.
Thus, the score of n is 1 + 4 = 5.

Example 2:
Input: n = 101
Output: 2
Explanation:
The digit 0 appears 1 time, contributing 0 * 1 = 0.
The digit 1 appears 2 times, contributing 1 * 2 = 2.
Thus, the score of n is 2.

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
int digitFrequencyScore(int n) {
    int sum=0;
    while(n!=0){
        int last=n%10;
        sum=sum+last;
        n/=10;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",digitFrequencyScore(n));
    return 0;
}