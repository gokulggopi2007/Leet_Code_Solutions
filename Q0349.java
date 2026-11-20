/*349. Intersection of Two Array */

/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
import java.util.*;
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        LinkedHashSet<Integer> set = new LinkedHashSet<>();
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                if(nums1[i]==nums2[j]){
                    set.add(nums1[i]);
                    break;
                }
            }
        }
        int[] arr=new int[set.size()];
        int i=0;
        for(int num:set){
            arr[i++]=num;
        }
        return arr;
    }
}
public class Q0349{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int nums1[]=new int[n];
        int m=sc.nextInt();
        int nums2[]=new int[m];
        for(int i=0;i<n;i++){
            nums1[i]=sc.nextInt();
        }
        for(int i=0;i<m;i++){
            nums2[i]=sc.nextInt();
        }
        Solution s=new Solution();
        int[] ans=s.intersection(nums1,nums2);
        for(int i=0;i<ans.length;i++){
            System.out.print(ans[i]+" ");
        }
        sc.close();
    }
}
