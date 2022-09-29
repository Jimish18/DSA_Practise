/*
Question - Diagonal Traverse

Link - https://leetcode.com/problems/diagonal-traverse/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
{
    vector<int> result;
    int n = mat.size();
    int m = mat[0].size();
    bool up = true;

    int i = 0,j = 0;

    while(i < n && j < m)
    {
        if(up)
        {
            while(i > 0 && j < m-1)
            {
                result.push_back(mat[i][j]);
                i--;
                j++;
            }
            result.push_back(mat[i][j]);
            if(j == m-1)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        else
        {
            while(j > 0 && i < n-1)
            {
                result.push_back(mat[i][j]);
                i++;j--;
            }
            result.push_back(mat[i][j]);
            if(i == n-1)
            {
                j++;
            }
            else
            {
                i++;
            }
        }

        up = !up;
    }

    


    return result;        
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> diaOrder = findDiagonalOrder(mat);

    for(int i = 0 ; i < diaOrder.size(); i++)
    {
        cout<<diaOrder[i]<<" ";
    }
    cout<<endl;

    return 0;
}