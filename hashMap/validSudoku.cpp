/*
Question - Valid Sudoku

Link - https://leetcode.com/problems/valid-sudoku/
*/

#include <bits/stdc++.h>
using namespace std;

// lengthy Code
// bool isValidSudoku(vector<vector<char>>& board) 
// {
//     unordered_set<char> st;

//     for(int i = 0; i < 9; i++)
//     {
//         for(int j = 0 ; j < 9; j++)
//         {
//             if(st.find(board[i][j]) != st.end())
//             {
//                 return false;
//             }
//             if(board[i][j] != '.')
//             {
//                 st.insert(board[i][j]);
//             }
//         }
//         st.clear();
//     }   

//     for(int i = 0; i < 9; i++)
//     {
//         for(int j = 0 ; j < 9; j++)
//         {
//             if(st.find(board[j][i]) != st.end())
//             {
//                 return false;
//             }
//             if(board[j][i] != '.')
//             {
//                 st.insert(board[j][i]);
//             }
//         }
//         st.clear();
//     }   

//     int n = 0;
//     for(int i = 0; i < 3; i++)
//     {        
//         for(int j = n ; j < n+3; j++)
//         {
//             for(int k = 0 ; k < 3; k++)
//             {
//                 if(st.find(board[j][k]) != st.end())
//                 {
//                     return false;
//                 }
//                 if(board[j][k] != '.')
//                 {
//                     st.insert(board[j][k]);
//                 }
//             }
//         }
//         st.clear();
//         n += 3;        
//     }

//     n = 0;
//     for(int i = 0; i < 3; i++)
//     {        
//         for(int j = n ; j < n+3; j++)
//         {
//             for(int k = 3 ; k < 6; k++)
//             {
//                 if(st.find(board[j][k]) != st.end())
//                 {
//                     return false;
//                 }
//                 if(board[j][k] != '.')
//                 {
//                     st.insert(board[j][k]);
//                 }
//             }
//         }
//         st.clear();
//         n += 3;        
//     }

//     n = 0;
//     for(int i = 0; i < 3; i++)
//     {        
//         for(int j = n ; j < n+3; j++)
//         {
//             for(int k = 6 ; k < 9; k++)
//             {
//                 if(st.find(board[j][k]) != st.end())
//                 {
//                     return false;
//                 }
//                 if(board[j][k] != '.')
//                 {
//                     st.insert(board[j][k]);
//                 }
//             }
//         }
//         st.clear();
//         n += 3;        
//     }

//     return true;     
// }

// Optimized Code
bool isValidSudoku(vector<vector<char>>& board) 
{
    vector<int> temp(9,0);
    vector<vector<int>> v1(9,temp); //for row check
    vector<vector<int>> v2(9,temp); // for column check
    vector<vector<int>> v3(9,temp);  // for sub-matrix check

    
    for(int i = 0; i < 9; i++)
    {
       for(int j = 0 ; j < 9 ; j++)
       {
            if(board[i][j] != '.')
            {
                int number = board[i][j] - '0'-1;
                int k = i/3 * 3 + j/3;

                if(v1[i][number] || v2[j][number] || v3[k][number])
                {
                    return false;
                }

                v1[i][number] = v2[j][number] = v3[k][number] = 1;
            }
       } 
    }
    return true;     
}

int main()
{
    return 0;
}