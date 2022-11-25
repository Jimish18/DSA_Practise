/*
Question - Sum Of Subarray Minimums

Link - https://leetcode.com/problems/sum-of-subarray-minimums/
*/

#include <bits/stdc++.h>
using namespace std;


int sumSubarrayMins(vector<int>& arr) 
{
    // O(n^2) Appraoch

    // int sum = 0;
    // int n = arr.size();

    // for(int i = 0 ; i < n; i++)
    // {
    //     int minValue = arr[i];
    //     for(int j = i; j < n ; j++)
    //     {
    //         minValue = min(minValue,arr[j]);

    //         sum += minValue;
    //     }
    // }  

    // O(n) Approach

    int sum = 0;
    int m = (int)pow(10,9)+7;
    int n = arr.size();
    vector<int> left;
    vector<int> right;
    stack<pair<int,int>> st;

    for(int i = 0; i < n; i++)
    {
        int count = 1;
        while(!st.empty() && arr[i] < st.top().first)
        {
            count += st.top().second;
            st.pop();
        }
        st.push({arr[i],count});
        left.push_back(count);
    }

    while(!st.empty()) st.pop();

    for(int i = n-1; i >= 0; i--)
    {
        int count = 1;
        while(!st.empty() && arr[i] <= st.top().first)
        {
            count += st.top().second;
            st.pop();
        }
        st.push({arr[i],count});
        right.insert(right.begin(),count);
    }

    int MOD = 1e9+7;
    for(int i = 0; i < n;i++)
    {
        long long prod = (left[i]*right[i])%MOD;
        prod *= arr[i]%MOD;
        sum += prod%MOD;
    }

    return sum;
}
int main()
{
    vector<int> v = {3,1,2,4};
    cout<<sumSubarrayMins(v)<<endl;

    return 0;
}