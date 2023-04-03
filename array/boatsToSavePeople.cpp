/*
Question - Boats To Save People

Link - https://leetcode.com/problems/boats-to-save-people/
*/

#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) 
{
    int n = people.size();
    sort(people.begin(),people.end());
    int i = 0;
    int j = n-1;
    int boatCount = 0;

    while(i < j)
    {
        if(people[i]+people[j] <= limit)
        {
            boatCount++;
            i++;
            j--;
        }
        else if(people[i] + people[j] > limit)
        {
            boatCount++;
            j--;
        }
    }    

    if(i == j) boatCount++;

    return boatCount;
}

int main()
{
    return 0;
}