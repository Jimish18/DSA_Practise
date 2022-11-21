/*
Question - Surrounded Regions

Link - https://leetcode.com/problems/surrounded-regions/
*/

#include <bits/stdc++.h>
using namespace std;


int n,m;
// Brute Force DFS (TLE)

// bool dfs(vector<vector<char>>& board,int i,int j)
// {
//     if(i < 0 || j < 0 || i >= n || j >= m)
//     {
//         return true;
//     }

//     if((i == 0 || j == 0 || i == n-1 || j == m-1))
//     {
//         if(board[i][j] == 'O') return false;
//     }

//     board[i][j] = 'X';

//     bool a = dfs(board,i+1,j);
//     bool b = dfs(board,i-1,j);
//     bool c = dfs(board,i,j-1);
//     bool d = dfs(board,i,j+1);

//     board[i][j] = 'O';


//     if(a && b && c && d) return true;

//     return false;
// }

// void solve(vector<vector<char>>& board) 
// {
//     n = board.size();
//     m = board[0].size();

//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             if(board[i][j] == 'O')
//             {
//                 if(dfs(board,i,j))
//                 {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }          
// }

void dfs(vector<vector<char>>& board,int i,int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;

    board[i][j] = '#';

    dfs(board,i-1,j);
    dfs(board,i+1,j);
    dfs(board,i,j-1);
    dfs(board,i,j+1);
}


void solve(vector<vector<char>>& board) 
{
    n = board.size();
    m = board[0].size();

    // for 1st and last column
    for(int i = 0 ; i < n; i++)
    {
        if(board[i][0] == 'O') dfs(board,i,0);

        if(board[i][m-1] == 'O') dfs(board,i,m-1);
    }   

    // 1st and last row
    for(int i = 0 ; i < m; i++)
    {
        if(board[0][i] == 'O') dfs(board,0,i);

        if(board[n-1][i] == 'O') dfs(board,n-1,i);
    }

    // Flipping # and O
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'O') board[i][j] = 'X';

            if(board[i][j] == '#') board[i][j] = 'O';
        }
    }
}

int main()
{
    return 0;
}