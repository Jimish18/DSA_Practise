/*
Problem Statement :->
    Reverse a stack without using extra space (within given stack)
*/

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int > &st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st,ele);

    st.push(topElement);
}

void reverse(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,element);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;


    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    
    
    return 0;
}