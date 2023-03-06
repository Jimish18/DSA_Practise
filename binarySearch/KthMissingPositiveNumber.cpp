/*
Question - Kth Missing Positive Number

Link - https://leetcode.com/problems/kth-missing-positive-number/
*/

#include <bits/stdc++.h>
using namespace std;

// O(N)
int findKthPositive(vector<int>& arr, int k) 
{
    vector<int> temp(2001);
    int count = 0;

    for(auto x : arr)
    {
        temp[x]++;
    }        

    for(int i = 1; i < 2001 ; i++)
    {
        if(temp[i] == 0) count++;

        if(count == k) return i;
    }

    return -1;
}

// O(log(N))
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int start = 0, end = n-1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] - (mid + 1) < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start + k;
}

int main()
{
    return 0;
}