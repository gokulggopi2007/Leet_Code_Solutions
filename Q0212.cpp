/*212. Word Search II*/

/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
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
class Trie{
public:
    string word;
    Trie* child[26];
    Trie(){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
};
class Solution {
public:
    vector<int> diff={0,1,0,-1,0};
    void dfs(int r,int c,int row,int col,vector<vector<char>>& board,Trie* par,vector<vector<bool>>& vis,vector<string>& ans){
        int chidx=board[row][col]-'a';
        if(par->child[chidx]==nullptr){
            return ;
        }
        Trie* curr=par->child[chidx];
        if(!curr->word.empty()){
            ans.push_back(curr->word);
            curr->word="";
        }
        for(int i=0;i<4;i++){
            int ar=row+diff[i],ac=col+diff[i+1];
            if(ar>=0 && ar<r && ac>=0 && ac<c && !vis[ar][ac]){
                vis[ar][ac]=true;
                dfs(r,c,ar,ac,board,curr,vis,ans);
                vis[ar][ac]=false;
            }
        }
        return ;
    }
    void buildTrie(string &word,int idx,Trie* par){
        if(idx==word.size()){
            par->word=word;
            return;
        }
        int chidx=word[idx]-'a';
        if(par->child[chidx]==nullptr){
            par->child[chidx]=new Trie();
        }
        buildTrie(word,idx+1,par->child[chidx]);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root=new Trie();
        for(string &word:words){
            buildTrie(word,0,root);
        }
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        vector<string> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vis[i][j]=true;
                dfs(r,c,i,j,board,root,vis,ans);
                vis[i][j]=false;
            }
        }
        return ans;
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
    int x;
    cin>>x;
    vector<string> words;
    for(int i=0;i<x;i++){
        string go;
        cin>>go;
        words.push_back(go);
    }
    Solution s;
    vector<string> gokul;
    gokul=s.findWords(board,words);
    for(int i=0;i<gokul.size();i++){
        cout<<gokul[i]<<" ";
    }
    return 0;
}