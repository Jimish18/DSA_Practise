/*
Question - Koko Eating Bananas

Link - https://leetcode.com/problems/koko-eating-bananas/
*/

#include <bits/stdc++.h>
using namespace std;

long long countHours(vector<int>& piles, long long mid)
{
    long long count = 0;

    for(auto x : piles) 
    {
        count += ceil((double)x/mid);
    }

    return count;
}

int minEatingSpeed(vector<int>& piles, int h) 
{
    int n = piles.size();
    long long sum = 0;
    long long maxi = 0;

    for(auto x : piles) 
    {
        sum += x;
        if(x > maxi) maxi = x;
    }

    long long right = maxi;
    long long left = ceil((double)sum/h);
    int mid;

    // cout<<left<<" "<<right<<endl<<endl;

    while(left < right)
    {
        mid = left + (right-left)/2;

        long long tempCount = countHours(piles,mid);
        // cout<<tempCount<<endl;

        if(tempCount > h) left = mid+1;
        else right = mid;
    }

    return left;    
}

int main()
{
    return 0;
}