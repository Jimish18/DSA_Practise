/*
Question - Evaluate Reverse Polish Notation

Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) 
{
    stack<int> st;
    int n = tokens.size();

    for(int i = 0; i < n ; i++)
    {
        int N = tokens[i].size();
        if(isdigit(tokens[i][N-1]))
        {
            st.push(stoi(tokens[i]));
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(tokens[i] == "+")
            {
                st.push(b+a);
            }
            else if(tokens[i] == "-")
            {
                st.push(b-a);
            }
            else if(tokens[i] == "*")
            {
                st.push(b*a);
            }
            else if(tokens[i] == "/")
            {
                st.push(b/a);
            }
        }
    } 

    return st.top();       
}

int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // {"4","13","5","/","+"}
    // {"2","1","+","3","*"}
    cout<<evalRPN(tokens)<<endl;

    return 0;
}