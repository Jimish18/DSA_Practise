/*
Question - Jump Game IV

Link - https://leetcode.com/problems/jump-game-iv/
*/

#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr) 
{
    int n = arr.size();
    unordered_map<long long ,vector<int>> umap;

    for(int i = 0;i < n ;i++)
    {
        umap[arr[i]].push_back(i);
    }

    queue<int> q;
    vector<bool> visited(n,false);
    q.push(0);
    int steps = 0;
    visited[0] = true;

    while(!q.empty())
    {
        int N = q.size();

        for(int i = 0 ; i < N;i++)
        {
            int index = q.front();
            q.pop();

            if(index == n-1) return steps;

            if(index+1 < n && !visited[index+1])
            {
                visited[index+1] = true;
                q.push(index+1); 
            }

            if(index-1 >= 0 && !visited[index-1])
            {
                visited[index-1] = true;
                q.push(index-1); 
            }

            for(auto x : umap[arr[index]])
            {
                if(!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }

            umap[arr[index]].clear();
        }
        steps++;
    }

    return -1;

}

int main()
{
    return 0;
}