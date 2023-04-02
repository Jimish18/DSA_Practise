/*
Question - Max Chunks To Make Sorted

Link - https://leetcode.com/problems/max-chunks-to-make-sorted/description/
*/

#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) 
{
    stack<int> st;
    int n = arr.size();
    int count = 0;
    int maxi = INT_MIN;

    for(int i = 0; i < n ; i++)
    {
        maxi = max(maxi,arr[i]);

        if(maxi == i) count++;
    }   
    return count; 
}

int main()
{
    return 0;
}