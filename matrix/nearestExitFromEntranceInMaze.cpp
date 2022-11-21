/*
Question - Nearest Exit From Entrance In Maze

Link - https://www.youtube.com/watch?v=OF4fg3z6hW8&ab_channel=TechAdorabyNivedita
*/

#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
{
    int n = maze.size();
    int m = maze[0].size();
    queue<pair<int,int>> q;
    q.push({entrance[0],entrance[1]});
    int level = 0;
    int N;
    
    vector<int> dc ={1,-1,0,0};
    vector<int> dr ={0,0,1,-1};  

    maze[entrance[0]][entrance[1]] = '+';

    while(!q.empty())
    {
        N = q.size();
        level++;
        
        for(int i = 0; i < N; i++)
        {
            pair<int,int> temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;

            for(int j = 0; j < 4; j++)
            {
                int newRow = row+dr[j];
                int newCol = col+dc[j];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m)
                {
                    if(maze[newRow][newCol] == '+') continue;

                    if(newRow == 0 || newCol == 0 || newRow == n-1 || newCol == m-1)
                    {
                        return level;
                    }


                    q.push({newRow,newCol});
                    maze[newRow][newCol] = '+';
                }
            }

        }
    }   

    return level;  
}

int main()
{
    return 0;
}