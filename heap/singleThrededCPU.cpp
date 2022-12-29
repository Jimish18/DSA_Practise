/*
Question - Single Threaded CPU

Link - https://leetcode.com/problems/single-threaded-cpu/
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

vector<int> getOrder(vector<vector<int>>& tasks) 
{
    priority_queue<pp,vector<pp>,greater<pp>> minH;
    vector<int> result;
    int n = tasks.size();
    sort(tasks.begin(),tasks.end());
    long long time = tasks[0][0];
    int i = 0;

    while(i < n || !minH.empty())
    {
        while(i < n && tasks[i][0] <= time)
        {
            minH.push({tasks[i][1],i});
            ++i;
        }

        pp temp = minH.top();
        minH.pop();
        time += temp.first;
        result.push_back(temp.second); 

        if(i < n && time < tasks[i][0] && minH.empty())
        {
            time = tasks[i][0];
        }       
    }

    
    return result;
}

int main()
{
    return 0;
}