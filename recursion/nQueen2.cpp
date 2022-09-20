/*
Question - nQueen II

Link - https://leetcode.com/problems/n-queens-ii/
*/

#include <bits/stdc++.h>
using namespace std;



bool isSafe(vector<string> &board,int x,int y)
{
    for(int row = x ; row >= 0; --row)
    {
        if(board[row][y] == 'Q')
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while(row>=0 && col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }

        row--;
        col--;
    }

    row = x;
    col = y;

    while(row>=0 && col < board.size())
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }

        row--;
        col++;
    }

    return true;
}

void nQueen(vector<string> &board,int x,vector<vector<string>> &result)
{
    if(x == board.size())
    {
        result.push_back(board);
        return;
    }

    for(int col = 0; col < board.size(); col++)
    {
        if(isSafe(board,x,col))
        {
            board[x][col] = 'Q';

            nQueen(board,x+1,result);

            board[x][col] = '.';
        }
    }    
}

int totalNQueens(int n) 
{
    vector<string> board(n,string(n,'.'));   

    vector<vector<string>> result;

    nQueen(board,0,result);
        
    return result.size();
}


int main()
{
    
    return 0;
}