/*
Question - Minimum Average Difference 

Link - https://leetcode.com/problems/minimum-average-difference/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minimumAverageDifference(vector<int>& nums) 
{
    int n = nums.size();
    vector<ll> preFix(n);
    vector<ll> suFix(n);
    pair<ll,ll> result = {LONG_MAX,0};

    preFix[0] = nums[0];
    suFix[n-1] = 0;
    
    for(int i = 1; i < n ; i++)
    {
        preFix[i] = preFix[i-1] + nums[i];
        suFix[n-i-1] = suFix[n-i] + nums[n-i];
    }

    for(int i = 0; i < n ;i++)
    {
        ll num1 = preFix[i]/(i+1);
        ll num2 = ((n-i-1) != 0) ? suFix[i]/(n-i-1) : 0;

        ll diff = abs(num1-num2);

        if(diff < result.first)
        {
            result.first = diff;
            result.second = i;
        }
    }

    return result.second;

}


int main()
{
    vector<int> v = {1,2,3,4,5};
    minimumAverageDifference(v);
    return 0;
}