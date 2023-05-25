/*
Question - MCM

Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab; 
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int N,int arr[],int i,int j)
{
    if(i >= j) return 0;

    int mn = INT_MAX;

    for(int k = i; k <= j-1; k++)
    {
        int tempAns = solve(N,arr,i,k) + solve(N,arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);

        mn = min(mn,tempAns);
    }

    return mn;
}

int matrixMultiplication(int N, int arr[])
{
    return solve(N,arr,1,N-1);
}

int main()
{
    return 0;
}