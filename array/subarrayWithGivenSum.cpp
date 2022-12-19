/*
Question - Subarray With Given Sum

Link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&company[]=Amazon&sortBy=submissions
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long s)
{
    int i = 0 , j = 0;
    long long sum = 0;

    while(i < n)
    {
        sum += arr[j];
        
        if(sum != s)
        {
            if(sum < s)
            {
                j++;
            }
            else if(sum > s)
            {
                if(i < j)
                {
                    sum -= arr[i];
                    i++;
                }
                else
                {
                    sum -= arr[j];
                    j++;
                }
            }
        }

        if(sum == s)
        {
            return {i+1,j+1};
        }
    }

    return {-1,-1};
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    // 1,2,3,7,5 -  12
    int n = 10;
    long long s = 15;
    vector<int> result = subarraySum(v,n,s);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}