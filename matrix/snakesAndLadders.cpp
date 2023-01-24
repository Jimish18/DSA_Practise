/*
Question - Snakes and Ladders

Link - https://leetcode.com/problems/snakes-and-ladders/description/
*/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> findCoordinates(int number , int n )
{
    int r = n - (number-1)/n  -1;
    int c = (number-1)%n;

    if(r%2 == n%2) return {r,n-1-c};
    else return {r,c};
}

int snakesAndLadders(vector<vector<int>> &board) 
{
    int n = board.size();
    vector<vector<bool>> visited(n , vector<bool> (n,false));
    queue<int> q;
    int steps = 0;

    q.push(1);
    visited[n-1][0] = true;

    while(!q.empty())
    {
        int qn = q.size();

        for(int i = 0; i < qn ; i++)
        {
            int number = q.front();
            q.pop();

            if(number == n*n) return steps;

            for(int j = 1; j <= 6; j++)
            {
                if(number+j > n*n) break;

                pair<int,int> coOrdinates = findCoordinates(number+j,n);
                int x = coOrdinates.first;
                int y = coOrdinates.second;

                if(visited[x][y] == true) continue;

                visited[x][y] = true;
                if(board[x][y] == -1) q.push(number+j);
                else q.push(board[x][y]);    

            }
        }
        steps++;
    }  

    return -1;  
}

int main()
{
    vector<vector<int>> board = {{-1,-1},{-1,3}};

    cout<<snakesAndLadders(board);
    return 0;
}