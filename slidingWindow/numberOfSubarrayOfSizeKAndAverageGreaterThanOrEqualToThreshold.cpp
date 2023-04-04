/*
Question - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Link - https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
*/

#include <bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) 
{
    int i = 0; 
    int j = 0;
    int n = arr.size();
    int sum = 0;
    int count = 0;

    while(j < n)
    {
        if(j-i+1 < k)
        {
            sum += arr[j];
            j++;
        }
        else
        {
            sum += arr[j];
            if(sum/k >= threshold) count++;

            sum -= arr[i];
            i++;
            j++;
        }
    }      

    return count;  
}

int main()
{
    return 0;
}