/*419. Battleships in a Board*/

/*
You are given an m x n matrix board where each cell is part of a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

Example 1:
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2

Example 2:
Input: board = [["."]]
Output: 0
 
Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is either '.' or 'X'.
*/
#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<iomanip>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
using namespace std;
#define ll long long int
class Solution {
    vector<int> diff={0,-1,0,1,0};
    private:
        void shipcount(int R,int C,int row,int col,vector<vector<char>>& board){
            if(board[row][col]=='X') board[row][col]='.';
            for(int i=0;i<4;i++){
                int ar=row+diff[i],ac=col+diff[i+1];
                if(ar>=0 && ar<R && ac>=0 && ac<C && board[ar][ac]=='X'){
                    shipcount(R,C,ar,ac,board);
                }
            }
        }
public:
    int countBattleships(vector<vector<char>>& board) {
        int R=board.size(),C=board[R-1].size();
        int btlsp=0;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(board[row][col]=='X'){
                    btlsp++;
                    shipcount(R,C,row,col,board);
                }
            }
        }
        return btlsp;
    }
}; 
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char>> board(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    Solution s;
    int ans=s.countBattleships(board);
    cout<<ans<<endl;
    return 0;
}