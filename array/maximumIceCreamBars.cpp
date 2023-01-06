/*
Question - Maximum Ice Cream Bars

Link - https://leetcode.com/problems/maximum-ice-cream-bars/description/
*/

#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) 
{
    int count  = 0;
    int n = costs.size();

    sort(costs.begin(),costs.end());

    for(int i = 0 ; i < n; i++)
    {
        if(costs[i] > coins) break;
        coins -= costs[i];
        count++;
    }    

    return count;
}

int main()
{
    return 0;
}