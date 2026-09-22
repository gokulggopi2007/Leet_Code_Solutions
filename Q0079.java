/*79. Word Search*/

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/
import java.util.*;
class Solution {
    int diff[]={0,1,0,-1,0};
    private boolean dfs(int r,int c,int row,int col,char board[][],String word,int idx){
        if(idx==word.length()-1){
            return true;
        }   
        char bkup=board[row][col];
        board[row][col]='*'; 
        for(int i=0;i<4;i++){
            int ar=row+diff[i],ac=col+diff[i+1];
            if(ar>=0 && ar<r && ac>=0 && ac<c && board[ar][ac]==word.charAt(idx+1)){
               boolean found=dfs(r,c,ar,ac,board,word,idx+1);
               if(found){
                return true;
               }
            }
        }
        board[row][col]=bkup;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int r=board.length,c=board[0].length;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word.charAt(0)){
                    boolean found=dfs(r,c,i,j,board,word,0);
                    if(found){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
class Q0079{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        char board[][]=new char[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=sc.next().charAt(0);
            }
        }
        String word=sc.next();
        Solution s=new Solution();
        boolean x=s.exist(board,word);
        System.out.println(x);
        sc.close();
    }
}