/*
Question - trapping rainwater

Link - https://leetcode.com/problems/trapping-rain-water/
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
{
    // O(n^2)
    // stack<int> st;
    // int ans = 0;
    // for(int i = 0 ; i < height.size(); i++)
    // {
    //     while(!st.empty() && height[st.top()] < height[i])
    //     {
    //         int t = st.top();
    //         st.pop();
    //         if(st.empty())
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             int tempLength = i - st.top()-1;
    //             ans += (min(height[st.top()],height[i]) - height[t])*tempLength;
    //         }
    //     }
    //     st.push(i);
    // }

    // O(n)
    int water = 0;
    int n = height.size();
    vector<int> lmax(n);
    lmax[0] = height[0];
    vector<int> rmax(n);
    rmax[n-1] = height[n-1];

    for(int i = 1 ; i < n; i++)
    {
        lmax[i] = max(height[i],lmax[i-1]);
    } 

    for(int i = n-2 ; i >= 0; i--)
    {
        rmax[i] = max(height[i],rmax[i+1]);
    }  

    for(int i = 1 ; i < n-1; i++)
    {
        water += min(lmax[i],rmax[i]) - height[i];
    }



    return water;      
}

int main()
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(v)<<endl;
    return 0;
}