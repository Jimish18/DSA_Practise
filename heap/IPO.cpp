/*
Question - IPO

Link - https://leetcode.com/problems/ipo/
*/

#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
{
    vector<pair<int,int>> tempArray;
    int n = profits.size();

    for(int i = 0; i< n; i++)
    {
        tempArray.push_back({capital[i],profits[i]});
    }

    sort(tempArray.begin(),tempArray.end());

    priority_queue<int> maxH;
    int i = 0;

    while(k--)
    {
        while(i < n && tempArray[i].first <= w)
        {
            maxH.push(tempArray[i].second);
            i++;            
        }

        w += maxH.top();
        maxH.pop();

    }

    return w;
}

int main()
{
    priority_queue<int> h;
    return 0;
}