/*
Question - Max Rectangle

Link - https://practice.geeksforgeeks.org/problems/max-rectangle/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> nextSmallerToRight(vector<int> temp,int m)
{
    stack<int> st;

    temp.push_back(-1);

    vector<int> toRight;

    for(int i = m; i >= 0; i--)
    {
        while(!st.empty() && temp[i] <= temp[st.top()]) st.pop();

        if(!st.empty()) toRight.insert(toRight.begin(),st.top()+1 );

        st.push(i);
    }

    return toRight;
}

vector<int> nextSmallerToLeft(vector<int> temp,int m)
{
    stack<int> st;

    temp.insert(temp.begin(),-1);

    vector<int> toLeft;

    for(int i = 0; i <= m; i++)
    {
        while(!st.empty() && temp[i] <= temp[st.top()]) st.pop();

        if(!st.empty()) toLeft.push_back(st.top());

        st.push(i);
    } 
    return toLeft;
}

int MAH(vector<int> preFix)
{
    int m = preFix.size();
    vector<int> toLeft = nextSmallerToLeft(preFix,m);
    vector<int> toRight = nextSmallerToRight(preFix,m);

    int maxArea = INT_MIN;

    for(int j = 0 ; j < m ; j++)
    {
        maxArea = max(maxArea , (toRight[j]-toLeft[j]-1)*preFix[j]);
    }

    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m) 
{
    vector<int> preFix(m,0);

    int maxArea = INT_MIN;

    for(int i = 0 ; i < n ; i++)
    {
        
        for(int j = 0 ; j < m ; j++)
        {
            preFix[j] += M[i][j];
            preFix[j] *= M[i][j];
        } 
        
        maxArea = max(maxArea , MAH(preFix));
        
    }

    return maxArea;
}

int main()
{
    vector<int> temp = {1,1,0,0};
    vector<int> ans = nextSmallerToRight(temp,temp.size());

    for(auto x : ans) cout<<x<<" ";
    return 0;
}