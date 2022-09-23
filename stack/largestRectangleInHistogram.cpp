/*
Question - Largest Ractangle in Histogram

Link - https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) 
{
    int i = 0 ;
    stack<int> st;
    int maxArea = 0;    
    heights.push_back(0);
    while(i < heights.size())
    {
        while(!st.empty() && heights[st.top()] > heights[i])
        {
            int t = st.top();
            int h = heights[t];
            st.pop();
            if(st.empty())
            {
                maxArea = max(maxArea,h*i);
            }
            else
            {
                int tempLength = i-st.top()-1; 
                maxArea = max(maxArea,h*tempLength);
            }
        }
        st.push(i);
        i++; 
    } 

    return maxArea;       
}

int main()
{
    vector<int> temp = {2,1,5,6,2,3};
    // {2,4}
    // {2,1,5,6,2,3}
    cout<<largestRectangleArea(temp)<<endl;

    return 0;
}