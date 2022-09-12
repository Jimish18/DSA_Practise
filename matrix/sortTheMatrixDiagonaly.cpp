/*
Question - Sort the Matrix Diagonaly

Link - https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
{
    int r = mat.size();
    int c = mat[0].size();
    int cStart;
    int rStart;
    vector<int> temp;

    for(int i = 0 ; i < c; i++)
    {
        cStart = i;
        rStart = 0;
        while(cStart < c && rStart < r)
        {
            temp.push_back(mat[rStart][cStart]);
            cStart++;
            rStart++;            
        }
        sort(temp.begin(),temp.end());

        cStart = i;
        rStart = 0;        
        while(temp.size() != 0)
        {
            mat[rStart][cStart] = temp.front();
            cStart++;
            rStart++;  
            temp.erase(temp.begin());          
        } 
    }

    for(int i = 1 ; i < r; i++)
    {
        cStart = 0;
        rStart = i;
        while(cStart < c && rStart < r)
        {
            temp.push_back(mat[rStart][cStart]);
            cStart++;
            rStart++;            
        }
        sort(temp.begin(),temp.end());

        cStart = 0;
        rStart = i;  
        while(temp.size() != 0)
        {
            mat[rStart][cStart] = temp.front();
            cStart++;
            rStart++;  
            temp.erase(temp.begin());          
        } 
    }

    return mat;
}

int main()
{
    vector<vector<int>> matrix = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};

    vector<vector<int>> diagonalPrint = diagonalSort(matrix);

    for(int i= 0 ; i < diagonalPrint.size(); i++)
    {
        for(int j = 0 ; j < diagonalPrint[i].size(); j++)
        {
            cout<<diagonalPrint[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}