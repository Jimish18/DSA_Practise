/*
Question - Keys and Rooms

Link - https://leetcode.com/problems/keys-and-rooms/
*/

#include <bits/stdc++.h>
using namespace std;


bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    int n = rooms.size();
    vector<bool> visited(n,false);
    unordered_map<int,vector<int>> umap;

    for(int i = 0 ; i < n ; i++)
    {
        for(auto x : rooms[i])
        {
            umap[i].push_back(x);
        }
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int room = q.front();
        q.pop();

        for(auto x : umap[room])
        {
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i]) return false;
    }
    return true;

}

int main()
{
    return 0;
}

