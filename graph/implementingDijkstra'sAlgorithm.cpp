/*
Quesion - Implementing Dijkstra Algorithm

Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

#include <bits/stdc++.h>
using namespace std;

// priority Queue Method 
// vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
// {
//     vector<int> ans(V,1e9);
//     priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> minH;
//     minH.push({0,S});
//     ans[S] = 0; 

//     while(!minH.empty())
//     {
//         int node = minH.top().second;
//         int wt = minH.top().first;
//         minH.pop();

//         for(auto x : adj[node])
//         {
//             int edgeWt = x[1];
//             int adjNode = x[0];

//             if(wt + edgeWt < ans[adjNode])
//             {
//                 ans[adjNode] = wt + edgeWt;
//                 minH.push({wt+edgeWt,adjNode});
//             }
//         }
//     }

//     return ans;
// }


// set method
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> ans(V,1e9);
    set<pair<int,int>> st;
    st.insert({0,S});
    ans[S] = 0; 

    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int wt = it.first;
        st.erase(it);

        for(auto x : adj[node])
        {
            int edgeWt = x[1];
            int adjNode = x[0];

            if(edgeWt + wt < ans[adjNode])
            {
                // check if there already exist this node 
                if(ans[adjNode] != 1e9) st.erase({ans[adjNode],adjNode});

                ans[adjNode] = edgeWt + wt;
                st.insert({ans[adjNode],adjNode});

            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}