/*3968. Maximum Manhattan Distance After All Moves*/

/*
You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'.

Starting from the origin (0, 0), each character represents one move on a 2D plane:

'U': Move up by 1 unit.
'D': Move down by 1 unit.
'L': Move left by 1 unit.
'R': Move right by 1 unit.
'_': Can be independently replaced with any one of 'U', 'D', 'L', or 'R'.
Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.

 

Example 1:

Input: moves = "L_D_"

Output: 4

Explanation:

One optimal choice is:

'L': (0, 0) -> (-1, 0)
'_' treated as 'D': (-1, 0) -> (-1, -1)
'D': (-1, -1) -> (-1, -2)
'_' treated as 'L': (-1, -2) -> (-2, -2)
The final Manhattan distance from the origin is |0 - (-2)| + |0 - (-2)| = 4.

Example 2:

Input: moves = "U_R"

Output: 3

Explanation:

One optimal choice is:

'U': (0, 0) -> (0, 1)
'_' treated as 'U': (0, 1) -> (0, 2)
'R': (0, 2) -> (1, 2)
The final Manhattan distance from the origin is |0 - 1| + |0 - 2| = 3.

 

Constraints:

1 <= moves.length <= 10^5
moves consists of only 'U', 'D', 'L', 'R', and '_'.
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
int maxDistance(char* moves) {
    int countU = 0, countD = 0;
    int countL = 0, countR = 0;
    int wildcard = 0;

    for (int i = 0; moves[i]; i++) {
        char c = moves[i];

        if (c == 'U') countU++;
        else if (c == 'D') countD++;
        else if (c == 'L') countL++;
        else if (c == 'R') countR++;
        else wildcard++;
    }

    int dx = abs(countR - countL);
    int dy = abs(countU - countD);

    int base = dx + dy;

    // each '_' can increase distance by 1
    return base + wildcard;
}
int main()
{
    char moves[100005];
    scanf("%s",moves);
    int ans=maxDistance(moves);
    printf("%d",ans);
    return 0;
}