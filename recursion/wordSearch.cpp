/*
Question - Word Search

Link - https://leetcode.com/problems/word-search/
*/

#include <bits/stdc++.h>
using namespace std;

int n , m , N;
vector<int> dr = {0,0,1,-1};
vector<int> dc = {1,-1,0,0};

bool findWord(vector<vector<char>>& board, string& word,int row,int col,vector<vector<bool>> &visit,int index)
{
    if(index >= N) return true;

    
    for(int i = 0; i < 4; i++)
    {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && !visit[newRow][newCol] &&  board[newRow][newCol] == word[index])
        {
            visit[newRow][newCol] = true;
            bool check = findWord(board,word,newRow,newCol,visit,index+1);

            if(check) return true;

            visit[newRow][newCol] = false;
        }
    }
    

    return false;
}

bool exist(vector<vector<char>>& board, string word) 
{
    n = board.size();
    m = board[0].size();
    N = word.size();
    vector<bool> temp(m,false);
    vector<vector<bool>> visit(n,temp); 
    int index = 0;  

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == word[index])
            {
                visit[i][j] = true;
                bool check = findWord(board,word,i,j,visit,index+1);

                if(check) return check;
                visit[i][j] = false;
            }
        }
    }  

    return false;     
}


int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string s = "ABCCED";

    cout<<exist(board,s)<<endl;
    return 0;
}