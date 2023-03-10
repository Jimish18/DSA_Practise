/*
Question - Design browser History

Link - https://leetcode.com/problems/design-browser-history/
*/

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
    
    stack<string> backStack;
    stack<string> forwardStack;

    public:
    
    BrowserHistory(string homepage) 
    {
        backStack.push(homepage);
        forwardStack = stack<string> ();
    }
    
    void visit(string url) 
    {
        backStack.push(url);
        forwardStack = stack<string> (); 
    }
    
    string back(int steps) 
    {
        while(steps > 0 && backStack.size() > 1)
        {
            forwardStack.push(backStack.top());
            backStack.pop();
            steps--;
        } 

        return backStack.top();
    }
    
    string forward(int steps) 
    {
        while(steps > 0 && forwardStack.size() > 0)
        {
            backStack.push(forwardStack.top());
            forwardStack.pop();
            steps--;
        } 

        return backStack.top();
    }
};



int main()
{    
    return 0;
}