/*
Question - best time to buy and sell stock

Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) 
{
    int maxPro = 0;
    int n = prices.size();
    int minValue = INT_MAX;

    for(int i = 0 ;i < n  ; i++)
    {
        if(prices[i] < minValue)
        {
            minValue = prices[i];
        }

        maxPro = max(maxPro,prices[i] - minValue);
    }

    return maxPro;

    
}

int main()
{
    vector<int > v = {7,6,4,3,1};
    // 7,1,5,3,6,4

    cout<<maxProfit(v)<<endl;
    return 0;
}