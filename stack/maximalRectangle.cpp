/*
Question - Maximal Ractangle

Link - https://leetcode.com/problems/maximal-rectangle/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToRight(vector<int> temp)
{
    int n = temp.size();
    vector<int> result(n);
    stack<int> st;

    for(int i = n-1; i >= 0 ; i--)
    {
        while(!st.empty() && (temp[st.top()]) >= (temp[i]))
        {
            st.pop();
        }

        if(st.empty()) result[i] = n;
        else result[i] = st.top();

        st.push(i);
    }

    return result;
}

vector<int> nextSmallerToLeft(vector<int> temp)
{
    int n = temp.size();
    vector<int> result(n);
    stack<int> st;

    for(int i = 0; i < n ; i++)
    {
        while(!st.empty() && (temp[st.top()]) >= (temp[i]))
        {
            st.pop();
        }

        if(st.empty()) result[i] = -1;
        else result[i] = st.top();

        st.push(i);
    }

    return result;
}

int areaOfHistogram(vector<int> temp)
{
    vector<int> left = nextSmallerToLeft(temp);
    vector<int> right = nextSmallerToRight(temp);

    int maxArea = 0;

    for(int i = 0; i < left.size(); i++)
    {
        maxArea = max(maxArea, (right[i]-left[i]-1)*temp[i]);
    }

    return maxArea;
}


int maximalRectangle(vector<vector<char>>& matrix) 
{
    vector<int> toCalculate;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> mat(n,vector<int> (m));

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(matrix[i][j] == '1') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }

    int maxRect = areaOfHistogram(mat[0]);
    for(int i = 1 ; i < n;i++)
    {
        for(int j = 0;j < m ; j++)
        {
            if(mat[i][j] == 0) continue;
            else mat[i][j] += mat[i-1][j];
        }

        maxRect = max(maxRect,areaOfHistogram(mat[i]));
    }

    return maxRect;    
}

int main()
{
    vector<vector<char>> temp = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // 
    cout<<maximalRectangle(temp)<<endl;
    return 0;
}