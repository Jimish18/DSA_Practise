/*
Question - Single Threaded CPU

Link - https://leetcode.com/problems/single-threaded-cpu/
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;

vector<int> getOrder(vector<vector<int>>& tasks) 
{
    priority_queue<pp,vector<pp>,greater<pp>> minH;
    vector<int> result;
    int n = tasks.size();
    vector<pp> tasks2;

    for(int i = 0 ; i < n; i++)
    {
        tasks2.push_back({tasks[i][0],{tasks[i][1],i}});
    }

    sort(tasks2.begin(),tasks2.end());
    long long time = tasks2[0].first;
    int i = 0;

    while(i < n || !minH.empty())
    {
        while(i < n && tasks2[i].first <= time)
        {
            minH.push({tasks2[i].second.first,{tasks2[i].second.second,tasks2[i].first}});
            ++i;
        }

        pp temp = minH.top();
        minH.pop();
        time += temp.first;
        result.push_back(temp.second.first); 

        if(i < n && time < tasks2[i].first && minH.empty())
        {
            time = tasks2[i].first;
        }       
    }

    
    return result;
}

int main()
{    
    return 0;
}