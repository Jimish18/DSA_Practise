/*
Question - Queens That can Attack The King

Link - https://leetcode.com/problems/queens-that-can-attack-the-king/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
{    
    vector<vector<int>> result;
    vector<bool> row(8,false);
    vector<vector<bool>> seen(8,row);

    for(auto i : queens)
    {
        seen[i[0]][i[1]] = true;
    }      

    vector<int> directions = {-1,0,1};

    for(int dx : directions)
    {
        for(int dy : directions)
        {
            if(dx == 0 && dy == 0)
            {
                continue;
            }
            int x = king[0];
            int y = king[1];

            while(x+dx >= 0 && x+dx < 8 && y+dy >= 0 && y+dy < 8)
            {
                x += dx;
                y += dy;

                if(seen[x][y])
                {
                    result.push_back({x,y});
                    break;
                }
            }


        }
    }

    return result;
}

int main()
{
    vector<vector<int>> queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king = {0,0};

    vector<vector<int>> attackingQueens = queensAttacktheKing(queens,king);

    for(int i = 0 ; i < attackingQueens.size(); i++)
    {
        for(int j = 0 ; j < attackingQueens[i].size(); j++)
        {
            cout<<attackingQueens[i][j]<<" ";
        }
        cout<<endl;
    }
}