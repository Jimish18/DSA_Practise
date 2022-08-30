/*
Question - Peak Index In Mountain Array

An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that 
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

 

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
 

Constraints:
3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
*/

#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) 
{
    int s = 0;
    int e = arr.size()-1;
    int m = s + (e-s)/2;
    int n = arr.size();

    while(e >= s)
    {
        if(arr[m]>arr[(m+n-1)%n] && arr[m] > arr[(m+1)%n])
        {
            return m;
        }
        else
        {
            if(m == 0)
            {
                if(arr[m+1] > arr[m] && arr[m+1] > arr[m+2])
                {
                    return m+1;
                }
            }
            if(arr[m]>arr[(m+n-1)%n] && arr[m] < arr[(m+1)%n])
            {
                s = (m+1)%n;
            }
            else
            {
                e = (m+n-1)%n;
            }
        }

        m = s + (e-s)/2;
    }
    return -1;
}

int main()
{
    vector<int > v = {3,9,8,6,4};
    cout<<peakIndexInMountainArray(v)<<endl;

    return 0;
}