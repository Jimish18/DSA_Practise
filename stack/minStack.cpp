/*
Question - Min Stack

Link - https://leetcode.com/problems/min-stack/
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) 
    {
        st.push(val);

        if(minSt.empty()) minSt.push(val);
        else
        {
            if(val <= minSt.top()) minSt.push(val);
        }
            
    }
    
    void pop() 
    {
        if(st.top() == minSt.top()) minSt.pop();

        st.pop();    
    }
    
    int top() 
    {
        return st.top();    
    }
    
    int getMin() 
    {
        return minSt.top();    
    }
};


int main()
{
    return 0;
}