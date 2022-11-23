/*
Question - Sudoku Solver

Link - https://leetcode.com/problems/sudoku-solver/
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board,char number,int row,int col)
{
    // Row 
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == number) return false;
    }

    // col
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == number) return false;
    }

    // grid
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[row/3 * 3 + i][col/3 * 3 + j] == number) return false;
        }
    }
    return true;
}

bool fill(vector<vector<char>>& board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9;j++)
        {
            if(!isdigit(board[i][j]))
            {
                for(int k = '1' ; k <= '9'; k++)
                {
                    if(isSafe(board,k,i,j))
                    {
                        board[i][j] = k;

                        bool check = fill(board);
                        
                        if(check) return true;
                        
                        board[i][j] = '.';
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) 
{
    fill(board);
}


int main()
{
    return 0;
}