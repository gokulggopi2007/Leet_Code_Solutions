/*37. Sudoku Solver*/

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
Output: 
[["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/
import java.util.Scanner;
class Solution {
    private int SMS=3;
    private int[] getfreecell(char board[][]){
        int R=9,C=9;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(board[row][col]=='.'){
                    return new int[]{row,col};
                }
            }
        }
        return new int[]{-1,-1};
    }
    private boolean solve(char board[][],boolean rf[][],boolean cf[][],boolean smf[][]){
        int cell[]=getfreecell(board);
        int row=cell[0],col=cell[1];
        if(row==-1 && col==-1){
            return true;
        }
        int smi=(row/SMS)*SMS+col/SMS;
        for(int dig=1;dig<=9;dig++){
            if(rf[row][dig]||cf[col][dig]||smf[smi][dig]){
                continue;
            }
            board[row][col]=(char)('0'+dig);
            rf[row][dig]=cf[col][dig]=smf[smi][dig]=true;
            boolean found=solve(board,rf,cf,smf);
            if(found){return true;}
            board[row][col]='.';
            rf[row][dig]=cf[col][dig]=smf[smi][dig]=false;
            
        }
        return false;
    }
    public void solveSudoku(char[][] board) {
        int R=board.length,C=board[R-1].length;
        boolean rf[][]=new boolean[R][10];
        boolean cf[][]=new boolean[C][10];
        boolean smf[][]=new boolean [9][10];
        for(int row=0;row<R;row++){
             for(int col=0;col<C;col++){
                if(board[row][col]!='.'){
                    int dig=board[row][col]-'0';
                    int smi=(row/SMS)*SMS+col/SMS;
                    rf[row][dig]=cf[col][dig]=smf[smi][dig]=true;
                }
             }
        }
        solve(board,rf,cf,smf);
        return ;
    }
}
public class Q0037 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        char board[][]=new char[9][9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                board[i][j]=sc.next().charAt(0);
            }
        }
        Solution s=new Solution();
        s.solveSudoku(board);
        for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
            System.out.print(board[i][j]+" ");
           }
           System.out.println();
        }
        sc.close();
    }
}
