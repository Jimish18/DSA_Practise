/*
Question - Largest Subarray With  Sum

Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>&A, int n)
{   
    // Your code here
    int sum = 0;
    int len = 0;
    unordered_map<int,int> umap;
    
    for(int i = 0 ; i < n;i++)
    {
        sum += A[i];
        
        if(sum == 0)
        {
            len = i+1;
        }
        else
        {
            if(umap.find(sum) != umap.end())
            {
                len = max(len,i-umap[sum]);
            }
            else
            {
                umap[sum] = i;
            }
        }
    }
    
    return len;
}

int main()
{
    return 0;
}