/*
Question - As  Far From Land As Possible

Link - https://leetcode.com/problems/as-far-from-land-as-possible/
*/

#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& grid) 
{
    int n = grid.size();
    queue<pair<pair<int,int>,int>> q;
    vector<int> col = {0,0,1,-1};
    vector<int> row = {1,-1,0,0};
    bool chk0 = true;
    bool chk1 = true;


    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(grid[i][j] == 0) chk0 = false;
            else if(grid[i][j] == 1)
            {
                chk1 = false;
                for(int l = 0; l < 4 ;l++)
                {
                    int newRow = i + row[l];
                    int newCol = j + col[l];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0)
                    {
                        q.push({{i,j},0});
                        break;
                    }
                }
            }
                
        }
    }

    if(chk0 || chk1) return -1;

    int curDist = 0;

    while(!q.empty())
    {
        pair<pair<int,int>,int> temp = q.front();
        q.pop();

        int curRow = temp.first.first;
        int curCol = temp.first.second;
        curDist = temp.second;
        for(int i = 0 ; i < 4; i++ )
        {
            int newRow = curRow + row[i];
            int newCol = curCol + col[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0)
            {
                q.push({{newRow,newCol},curDist+1});
                grid[newRow][newCol] = 1;
            }
        }

        
    }

    return curDist;


    
}

int main()
{
    return 0;
}