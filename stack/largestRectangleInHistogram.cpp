/*
Question - Largest Ractangle in Histogram

Link - https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> previosSmallerElement(vector<int> array)
{
    vector<int> result;
    stack<int> st;
    array.insert(array.begin(),-1);

    int i = 1;
    st.push(0);
    while(i < array.size())
    {
        while(!st.empty() && array[st.top()] > array[i])
        {
            st.pop();
        }
        result.push_back(array[st.top()]);
        st.push(i);
        i++;
    }

    return result;
}

vector<int> nextSmallerElement(vector<int> array)
{
    vector<int> result;
    stack<int> st;
    int lastNum = array[array.size()-1];
    array.push_back(lastNum);
    int i = array.size()-2;
    st.push(array.size()-1);

    while(i >= 0)
    {
        while(!st.empty() && array[st.top()] > array[i])
        {
            // st.pop();
            result.insert(result.begin(),array[st.top()]]);
        }
        result.insert(result.begin(),array[st.top()]);
        st.push(i);
        i--;
    }

    return result;
}


int largestRectangleArea(vector<int>& heights) 
{
    // Approach 1
    // int i = 0 ;
    // stack<int> st;
    // int maxArea = 0;    
    // heights.push_back(0);
    // while(i < heights.size())
    // {
    //     while(!st.empty() && heights[st.top()] > heights[i])
    //     {
    //         int t = st.top();
    //         int h = heights[t];
    //         st.pop();
    //         if(st.empty())
    //         {
    //             maxArea = max(maxArea,h*i);
    //         }
    //         else
    //         {
    //             int tempLength = i-st.top()-1; 
    //             maxArea = max(maxArea,h*tempLength);
    //         }
    //     }
    //     st.push(i);
    //     i++; 
    // } 

    // Approach 2
    int maxArea = 0;
    vector<int> previousSmaller = previosSmallerElement(heights);
    vector<int> nextSmaller = nextSmallerElement(heights);

    for(int i = 0 ;i < heights.size(); i++)
    {
        int curr = (nextSmaller[i] - previousSmaller[i] -1)*heights[i];
        maxArea = max(maxArea,curr); 
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