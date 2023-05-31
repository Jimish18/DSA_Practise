/*
Question - Design Underground System

Link - https://leetcode.com/problems/design-underground-system/
*/

#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem 
{
    public:
    unordered_map<int,pair<string,int>> chkIn,chkOut;
    unordered_map<string,vector<int>> diff;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        chkIn[id] = {stationName,t};    
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        chkOut[id] = {stationName,t};   

        string key = chkIn[id].first +"_"+ chkOut[id].first;
        diff[key].push_back(chkOut[id].second-chkIn[id].second);
    }  
    
    double getAverageTime(string startStation, string endStation) 
    {
        int total = 0;

        string key = startStation + "_" + endStation;

        for(auto x : diff[key])
        {
            total += x;
        }

        double ans = (double)(total)/(diff[key].size());

        return ans;
    }
};

int main()
{
    return 0;
}