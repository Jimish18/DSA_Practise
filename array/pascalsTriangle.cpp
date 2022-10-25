/*
Question - Pascal's Triangle

Link - https://leetcode.com/problems/pascals-triangle/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) 
{
    vector<vector<int>> result;

    for(int i = 0 ; i < numRows; i++)
    {
        vector<int> temp;
        for(int j = 0; j <=i; j++)
        {
            if(j == 0 || j == i)
            {
                temp.push_back(1);
                continue;
            }

            temp.push_back(result[i-1][j-1] + result[i-1][j]);
        }

        result.push_back(temp);
    }     
    return result;   
}

int main()
{
    vector<vector<int>> v = generate(3);

    for(int i = 0 ; i < v.size(); i++)
    {
        for(int j = 0 ; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}