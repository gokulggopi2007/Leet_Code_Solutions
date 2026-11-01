/*204. Count Primes*/

/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
 

Constraints:
0 <= n <= 5 * 10^6
*/
import java.util.*;
class Solution {
    public int countPrimes(int n) {
        boolean prime[]=new boolean[n];
        Arrays.fill(prime,true);
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*2;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
            }
        }
        return count;
    }
}
public class Q0204{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Solution s=new Solution();
        System.out.println(s.countPrimes(n));
        sc.close();
    }
}