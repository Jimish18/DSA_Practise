/*
Question - Possible Bipartition

Link - https://leetcode.com/problems/possible-bipartition/
*/

#include <bits/stdc++.h>
using namespace std;

bool groupCheck(unordered_set<int> &green,int x,int y)
{
    if((green.find(x) != green.end()) && (green.find(y) != green.end()))
    {
        return true;
    }

    return false;
}

bool groupOne(unordered_set<int> &green,int x)
{
    if(green.find(x) != green.end()) return true;
    
    return false;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
{
    unordered_map<int,vector<int>> umap;
    int N = dislikes.size();

    for(int i = 0; i < N; i++)
    {
        umap[dislikes[i][0]].push_back(dislikes[i][1]);
    }        

    unordered_set<int> green;
    unordered_set<int> red;
    
    for(auto x : umap)
    {
        for(auto i : x.second)
        {
            if(green.size() && red.size())
            {
                if(groupCheck(green,x.first,i) || groupCheck(red,x.first,i)) return false;
            }
            else if(groupOne(green,x.first))
            {
                red.insert(i);
            }
            else if(groupOne(red,x.first))
            {
                green.insert(i);
            }
            else
            {
                green.insert(x.first);
                red.insert(i);
            }

        }
    }

    return true;

}

int main()
{
    return 0;
}