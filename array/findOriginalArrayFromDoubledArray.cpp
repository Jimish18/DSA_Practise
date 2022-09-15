/*
Question - find Original Array From Doubled Array

Link - https://leetcode.com/problems/find-original-array-from-doubled-array/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) 
{
    vector<int> original;
    unordered_map<int,int> umap;
    int count = 0;

    if(changed.size()%2 != 0)
    {
        return {};
    }

    sort(changed.begin(),changed.end());

    for(int i = 0 ; i < changed.size(); i++)
    {
        umap[changed[i]]++;
    }

    for(int i = 0 ; i < changed.size(); i++)
    {
        if(umap.find(changed[i]*2) != umap.end() && (umap[changed[i]*2] > 0) && (umap[changed[i]] > 0))
        {
            if(changed[i] == 0 && umap[changed[i]]%2 != 0)
            {
                break;
            }
            original.push_back(changed[i]);
            umap[changed[i]]--;
            umap[changed[i]*2]--;
            count++;

            if(count == changed.size()/2)
            {
                break;
            }
        }
    }

    if(count == changed.size()/2)
    {
        return original ;
    }
    else
    {
        return {};
    }
}


int main()
{
    vector<int> v = {4,4,16,20,8,8,2,10};

    // 6,3,0,1
    // 1,3,4,2,6,8
    // 1
    // 4,4,16,20,8,8,2,10
    vector<int> original = findOriginalArray(v);

    for(int i = 0 ; i < original.size(); i++)
    {
        cout<<original[i]<<" ";
    }
    cout<<endl;
    return 0;
}