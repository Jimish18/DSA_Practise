/*
Question - Maximum Number Of Groups Entering a Competition

Link - https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
*/

#include <bits/stdc++.h>
using namespace std;

int maximumGroups(vector<int>& grades) 
{
    sort(grades.begin(),grades.end());

    int count = 0;
    int n = grades.size();
    int i = 1;

    while(n > 0)
    {
        count++;
        n = n-i;
        i++;
        if(n < 0)
        {
            break;
        }
        
        if(n-i != 0 && n-i < i)
        {
            n -= i;
        }
    }        

    return count;
}

int main()
{
    vector<int> v = {10,6,12,7,3,5};
    cout<<maximumGroups(v)<<endl;
    // maximumGroups(v);
    // cout<<5%2<<endl;
    return 0;
}