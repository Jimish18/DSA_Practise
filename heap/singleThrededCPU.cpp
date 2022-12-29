/*
Question - Single Threaded CPU

Link - https://leetcode.com/problems/single-threaded-cpu/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getOrder(vector<vector<int>>& tasks) 
{
    priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> minH;
    int n = tasks.size();
    long long time = tasks[0][0];
    vector<int> result;
    int j = 1;

    sort(tasks.begin(),tasks.end());
    minH.push({tasks[0][1],tasks[0][0],0});
    
    while(!minH.empty())
    {
        vector<long long> temp = minH.top();
        minH.pop();
        result.push_back(temp[2]);
        time += temp[1];

        while(tasks[j][1] <= time)
        {
            minH.push({tasks[j][1],tasks[j][0],j});
            j++;
        }

    }

    return result;

}

int main()
{
    return 0;
}