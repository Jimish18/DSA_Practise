/*
Question - Largest Ractangle in Histogram

Link - https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToRight(vector<int> temp)
{
    vector<int> result(temp.size()); 
    stack<int> st;

    for(int i = temp.size()-1 ; i >= 0; i--)
    {
        while(!st.empty() && temp[st.top()] >= temp[i])
        {
            st.pop();
        }
        if(st.empty()) result[i] = temp.size();
        else result[i] = st.top();
        
        st.push(i);
    }

    return result;
}

vector<int> nextSmallerToLeft(vector<int> temp)
{
    vector<int> result(temp.size());
    stack<int> st;

    for(int i = 0; i < temp.size(); i++)
    {
        while(!st.empty() && temp[st.top()] >= temp[i])
        {
            st.pop();
        }

        if(st.empty()) result[i] = -1;
        else result[i] = st.top();

        st.push(i);
    }

    return result;
}

int largestRectangleArea(vector<int>& heights) 
{
    vector<int> right = nextSmallerToRight(heights);
    vector<int> left = nextSmallerToLeft(heights);
    int maxArea = 0;

    for(int i = 0; i < heights.size(); i++)
    {
        maxArea = max(maxArea , (right[i]-left[i]-1)*heights[i]);
    }

    return maxArea;
}

int main()
{
    vector<int> temp = {6,2,5,4,5,1,6};
    cout<<largestRectangleArea(temp)<<endl;

    return 0;
}