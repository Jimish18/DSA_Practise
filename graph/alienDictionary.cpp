/*
Question - Alien's Dictionary

Link - https://practice.geeksforgeeks.org/problems/alien-dictionary/1
*/

#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K) 
{
    vector<vector<int>> adj(K);

    for(int i = 1 ; i < N; i++)
    {
        for(int j = 0; j < min(dict[i].length(),dict[i-1].length()); j++)
        {
            if(dict[i][j] != dict[i-1][j])
            {
                adj[dict[i-1][j]-'a'].push_back(dict[i][j]-'a');
                break;
            }
        }
    } 

    vector<int> indegree(K,0);

    for(int i = 0; i < K ; i++)
    {
        for(auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < K;i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> order;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for(auto x : adj[node])
        {
            indegree[x]--;

            if(indegree[x] == 0) q.push(x);
        }
    }

    string str = "";

    for(int i = 0; i < K; i++)
    {
        char t = order[i]+97;
        str += t;
    }

    return str;
}

int main()
{
    string dict[] = {"baa","abcd","abca","cab","cad"}; 
    cout<<findOrder(dict,5,4)<<endl;

    // int a = 2;
    // char t = a+97;
    // cout<<t<<endl;
    return 0;
}