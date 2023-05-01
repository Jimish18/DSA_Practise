/*
Question - Average Salary Excluding the Minimum and Maximum Salary

Link - https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
*/

#include <bits/stdc++.h>
using namespace std;

double average(vector<int>& salary) 
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int n = salary.size();
    int ava = 0;

    for(int i = 0; i < n ; i++)
    {
        ava += salary[i];
        mini = min(salary[i],mini);
        maxi = max(salary[i],maxi);
    }  

    ava -= (maxi+mini);
    
    return (double)(ava)/(n-2);
}

int main()
{
    return 0;
}