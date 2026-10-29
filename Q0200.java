/*200. NUmber of Islands*/

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/
import java.util.*;
class Solution {
    int diff[][]={{0,-1},{0,1},{-1,0},{1,0}};
    private void dfs(int r,int c,int row,int col,char grid[][]){
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int ar=row+diff[i][0],ac=col+diff[i][1];
            if(ar>=0 && ar<r && ac>=0 && ac<c && grid[ar][ac]=='1'){
                dfs(r,c,ar,ac,grid);
            }
        }
    }
    public int numIslands(char[][] grid) {
        int r=grid.length,c=grid[0].length;
        int is=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    is++;
                    dfs(r,c,i,j,grid);
                }
            }
        }
        return is;
    }
}
public class Q0200{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        char[][] grid=new char[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=sc.next().charAt(0);
            }
        }
        Solution s=new Solution();
        System.out.println(s.numIslands(grid));
        sc.close();
    }
}