/*74. Search a 2D Matrix*/

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
*/
import java.util.*;
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
         int R=matrix.length,C=matrix[0].length;
        int row=0,col=C-1;
        while(row<R && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
}
class Q0074{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int row=sc.nextInt();
        int col=sc.nextInt();
        int matrix[][]=new int[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        int target=sc.nextInt();
        Solution s=new Solution();
        boolean x=s.searchMatrix(matrix,target);
        System.out.println(x);
        sc.close();
    }
}