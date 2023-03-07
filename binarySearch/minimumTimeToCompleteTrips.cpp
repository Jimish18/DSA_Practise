/*
Question - Minimum Time to Complete Trips

Link - https://leetcode.com/problems/minimum-time-to-complete-trips/
*/

#include <bits/stdc++.h>
using namespace std;

long long temp(vector<int>& time,long long midTime)
{
    long long sum = 0;

    for(auto x : time)
    {
        sum += midTime/(long long)x;
    }

    return sum;
}

long long minimumTime(vector<int>& time, int totalTrips) 
{
    long long left = 0;
    long long mini = time[0];

    for(auto x : time)
    {
        if(mini < x) mini = x;
    }        

    long long right = mini*totalTrips;

    while(left < right)
    {
        long long mid = left + (right-left)/2;

        long long tripWithMidTime = temp(time,mid);

        if(tripWithMidTime < totalTrips) left = mid+1;
        else right = mid;
    }

    return left;

}

int main()
{
    return 0;
}