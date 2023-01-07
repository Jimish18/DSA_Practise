/*
Question - Gas Station

Link - https://leetcode.com/problems/gas-station/
*/

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    int n = cost.size();
    int costSum = 0;
    int gasSum = 0;

    for(int x : cost)
    {
        costSum += x;
    }

    for(int x : gas)
    {
        gasSum += x;
    }     

    if(gasSum < costSum) return -1;

    int total = 0;
    int index = 0;

    for(int i = 0 ; i < n ; i++)
    {
        total += gas[i] - cost[i];

        if(total < 0)
        {
            total = 0;
            index = i+1;
        }
    }   

    return index;

}

int main()
{
    return 0;
}