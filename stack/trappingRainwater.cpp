/*
Question - trapping rainwater

Link - https://leetcode.com/problems/trapping-rain-water/
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
{
    stack<int> st;
    int ans = 0;
    for(int i = 0 ; i < height.size(); i++)
    {
        while(!st.empty() && height[st.top()] < height[i])
        {
            int t = st.top();
            st.pop();
            if(st.empty())
            {
                break;
            }
            else
            {
                int tempLength = i - st.top()-1;
                ans += (min(height[st.top()],height[i]) - height[t])*tempLength;
            }
        }
        st.push(i);
    }  

    return ans;      
}

int main()
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(v)<<endl;
    return 0;
}