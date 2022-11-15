/*
Question - Remove Stones to Minimize the Total

Link - https://leetcode.com/problems/remove-stones-to-minimize-the-total/
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// int minStoneSum(vector<int>& piles, int k) 
// {
//     priority_queue<pair<int,int>> maxH;
//     int n = piles.size();

//     for(int i = 0 ; i < n; i++)
//     {
//         maxH.push({piles[i],i});
//     }        

//     while(k)
//     {
//         piles[maxH.top().second] = ceil((double)(maxH.top().first)/2);
//         int i = maxH.top().second;
//         int value = ceil((double)(maxH.top().first)/2);
//         maxH.pop();
//         maxH.push({value,i});
//         k--;
//     }

//     int sum = 0;

//     for(int x : piles)
//     {
//         sum += x;
//     }

//     return sum;
// }

// Optimized Approach
int minStoneSum(vector<int>& piles, int k) 
{
    priority_queue<int> maxH(piles.begin(),piles.end());
    int n = piles.size();
    int sum = accumulate(piles.begin(),piles.end(),0);
    
    while(k--)
    {
        int a = maxH.top();
        maxH.pop();
        maxH.push(a - a/2);
        sum -= a/2;
    }

    return sum;
}

int main()
{
    vector<int> v = {4,3,6,7};
    // {5,4,9} 2
    int k = 3;

    cout<<minStoneSum(v,k)<<endl;
    return 0;
}