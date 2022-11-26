/*
Question - Maximum Profit In Job Scheduling

Link - https://leetcode.com/problems/maximum-profit-in-job-scheduling/
*/

#include <bits/stdc++.h>
using namespace std;

// o(n^2) Approach
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
{
    int n = startTime.size();
    vector<vector<int>> jobs;
    
    for(int i = 0; i < n; i++)
    {
        jobs.push_back({endTime[i],startTime[i],profit[i]});
    }

    sort(jobs.begin(),jobs.end());

    int result = 0;
    vector<int> dp(n);

    for(int i = 0; i < n; i++)
    {
        dp[i] = jobs[i][2];
        if(i == 0)
        {
            result = max(result,dp[i]);
            continue;
        }

        dp[i] = max(dp[i],dp[i-1]);

        int currTime = jobs[i][1];

        for(int j = i-1; j >= 0; j--)
        {
            if(jobs[j][0] <= currTime)
            {
                dp[i] = max(dp[i],(dp[j]+jobs[i][2]));
                break;
            }
        }

        result = max(result,dp[i]);
    }       

    return result;
}

int main()
{
    return 0;
}