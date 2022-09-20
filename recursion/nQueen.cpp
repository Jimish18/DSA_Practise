/*
Question - nQueen I

Link - https://leetcode.com/problems/n-queens/
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

vector<vector<string>> solveNQueens(int n) 
{
    string s = "";
    for(int i = 0 ;i < n; i++)
    {
        s += '.';
    }
    vector<string> board;

    for(int i = 0 ;i < n; i++)
    {
        board.push_back(s);
    }

    vector<vector<string>> result;

    nQueen(board,0,result);

    return result;
}


int main()
{
    vector<vector<string>> resultQueen = solveNQueens(4);

    for(int i = 0; i< resultQueen.size(); i++)
    {
        for(int j = 0 ; i < resultQueen[i].size(); j++)
        {
            for(int k = 0 ; k < resultQueen[i][j].length(); k++)
            {
                cout<<resultQueen[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

    
    return 0;
}