/*
Question - Car Pooling 

Link - https://leetcode.com/problems/car-pooling/
*/

#include <bits/stdc++.h>
using namespace std;

// Heap Approach O(NlogN)
// bool carPooling(vector<vector<int>>& trips, int capacity) 
// {
//     int n = trips.size();
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;

//     for(int i = 0; i < n; i++)
//     {
//         minH.push({trips[i][1],trips[i][0]});
//         minH.push({trips[i][2],-trips[i][0]});
//     }

//     int check = 0;

//     while(!minH.empty())
//     {
//         check += minH.top().second;

//         if(check > capacity) return false;

//         minH.pop();
//     }

//     return true;    
// }

// Array Approach O(N)
bool carPooling(vector<vector<int>>& trips, int capacity) 
{
    int n = trips.size();
    vector<int> stops(1001,0);

    for(int i = 0; i < n; i++)
    {
        stops[trips[i][1]] += trips[i][0];
        stops[trips[i][2]] -= trips[i][0];
    }

    int check = 0;

    for(int x : stops)
    {
        check += x;

        if(check > capacity) return false;
    }

    return true;    
}

int main()
{
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 5;

    cout<<carPooling(trips,capacity)<<endl;
    return 0;
}