/*
Question - Reduce Array Size to The Half

Link - https://leetcode.com/problems/reduce-array-size-to-the-half/


*/

#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr) 
{
    unordered_map<int,int> umap;
    priority_queue<int> maxH;

    for(int i = 0; i < arr.size(); i++)
    {
        umap[arr[i]]++;
    }        

    for(auto x : umap)
    {
        maxH.push(x.second);
    }

    int n = arr.size();
    int count = 0;
    int m = n;

    while(m > n/2)
    {
        m -= maxH.top();
        maxH.pop();
        count++;
    }

    return count;
}


int main()
{
    return 0;
}