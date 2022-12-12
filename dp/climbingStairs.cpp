/*
Question - Climbing Stairs

Link - https://leetcode.com/problems/climbing-stairs/
*/


#include <bits/stdc++.h>
using namespace std;

// int cnt = 0;

// void countAttemt(int n)
// {
//     if(n < 0) return;
//     if(n == 0)
//     {
//         cnt++;
//         return;
//     }

//     countAttemt(n-1);

//     countAttemt(n-2);
// }

int climbStairs(int n) 
{
    // countAttemt(n);
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i < n+1; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}


int main()
{
    return 0;
}