/*
Question - Maximum Profit In Job Scheduling

Link - https://leetcode.com/problems/maximum-profit-in-job-scheduling/
*/

#include <bits/stdc++.h>
using namespace std;

// o(n^2) Approach
// int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
// {
//     int n = startTime.size();
//     vector<vector<int>> jobs;
    
//     for(int i = 0; i < n; i++)
//     {
//         jobs.push_back({endTime[i],startTime[i],profit[i]});
//     }

//     sort(jobs.begin(),jobs.end());

//     int result = 0;
//     vector<int> dp(n);

//     for(int i = 0; i < n; i++)
//     {
//         dp[i] = jobs[i][2];
//         if(i == 0)
//         {
//             result = max(result,dp[i]);
//             continue;
//         }

//         dp[i] = max(dp[i],dp[i-1]);

//         int currTime = jobs[i][1];

//         for(int j = i-1; j >= 0; j--)
//         {
//             if(jobs[j][0] <= currTime)
//             {
//                 dp[i] = max(dp[i],(dp[j]+jobs[i][2]));
//                 break;
//             }
//         }

//         result = max(result,dp[i]);
//     }       

//     return result;
// }

// O((n*Log(n)))
int search(vector<vector<int>> &jobs,int curr)
{
    int l = 0 ; 
    int r = curr-1;
    int ans = -1;

    while(l <= r)
    {
        int mid = (l+r)/2;

        if(jobs[mid][0] <= jobs[curr][1])
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return ans;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
{
    int n = startTime.size();
    vector<vector<int>> jobs;
    
    for(int i = 0; i < n; i++)
    {
        jobs.push_back({endTime[i],startTime[i],profit[i]});
    }

    sort(jobs.begin(),jobs.end());

    vector<int> dp(n,0);
    dp[0] = jobs[0][2];
    int result = dp[0];

    for(int i = 1; i < n; i++)
    {
        int incl = jobs[i][2];
        dp[i] = incl;
        int curr = i;
        int l = search(jobs,curr);
        if(l != -1) dp[i] += dp[l];
        dp[i] = max(dp[i],dp[i-1]);
        result = max(result,dp[i]);
    }       

    return result;
}

int main()
{
    return 0;
}