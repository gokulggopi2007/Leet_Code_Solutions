/*75.Sort Colors*/

/*
You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Explanation:
The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
Explanation:
The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/
import java.util.*;
class Solution {
    public void sortColors(int[] nums) {
        int a=0,b=0,c=0;
        for(int n:nums){
            if(n==0){
                a++;
            }
            else if(n==1){
                b++;
            }
            else{
                c++;
            }
        }
        for(int i=0;i<a;i++){
            nums[i]=0;
        }
        for(int j=a;j<a+b;j++){
            nums[j]=1;
        }
        for(int i=a+b;i<nums.length;i++){
            nums[i]=2;
        }
    }
}
class Q0075{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int nums[]=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        Solution s=new Solution();
        s.sortColors(nums);
        for(int i=0;i<n;i++){
            System.out.print(nums[i]+" ");
        }
        sc.close();
    }
}