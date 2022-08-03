/*
Question - Design browser History

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 

Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"

TestCase :

Input->
["BrowserHistory","visit","visit","back","visit","forward","visit","visit","forward","visit","back","visit","visit","forward"]
[["esgriv.com"],["cgrt.com"],["tip.com"],[9],["kttzxgh.com"],[7],["crqje.com"],["iybch.com"],[5],["uun.com"],[10],["hci.com"],["whula.com"],[10]]

Output->
[null,null,null,"esgriv.com",null,"kttzxgh.com",null,null,"iybch.com",null,"esgriv.com",null,null,"whula.com"]

*/

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
    
    vector<string> backStack;
    vector<string> forwardStack;

    public:
    
    BrowserHistory(string homepage) 
    {
        backStack.push_back(homepage);
    }
    
    void visit(string url) 
    {
        int count = forwardStack.size();
        while(count > 0)
        {
            backStack.pop_back();
            count--;
        }
        backStack.push_back(url); 

        forwardStack.clear();
    }
    
    string back(int steps) 
    {
        if(steps >= backStack.size())
        {
            for(int i = backStack.size()-1 ; i >= 0 ; i--)
            {
                forwardStack.push_back(backStack[i]);
            }
            return backStack[0];
        }
        else
        {
            int count = steps ;
            for(int i = backStack.size()-1-forwardStack.size() ; count > 0 ; i--)
            {
                forwardStack.push_back(backStack[i]);
                count--;
            }
            return backStack[backStack.size()-1-forwardStack.size()];
        }
    }
    
    string forward(int steps) 
    {
        int count = steps;
        int actualCount = 0;

        if(steps >= forwardStack.size())
        {
            if(forwardStack.size() == 0)
            {
                return backStack[backStack.size()-1];
            }
            return forwardStack[0];
        }
        else
        {
            int count = steps;
            while(count > 0)
            {
                forwardStack.pop_back();
                count--;
            }
            return forwardStack[forwardStack.size()-steps];
        }
    }
};

int main()
{
    // BrowserHistory* b = new BrowserHistory("leetcode.com");
    // b->visit("google.com");
    // b->visit("facebook.com");
    // b->visit("youtube.com");
    // cout<<b->back(1)<<endl;
    // cout<<b->back(1)<<endl;
    // cout<<b->forward(1)<<endl;
    // b->visit("linkedin.com");
    // cout<<b->forward(2)<<endl;
    // cout<<b->back(2)<<endl;
    // cout<<b->back(7)<<endl;

    BrowserHistory* b = new BrowserHistory("esgriv.com");
    b->visit("cgrt.com");
    b->visit("tip.com");
    cout<<b->back(9)<<endl;
    b->visit("kttzxgh.com");
    cout<<b->forward(7)<<endl;
    b->visit("crqje.com");
    b->visit("iybch.com");
    cout<<b->forward(5)<<endl;
    b->visit("uun.com");
    cout<<b->back(10)<<endl;
    b->visit("hci.com");
    b->visit("whula.com");
    cout<<b->forward(10)<<endl;

    
    return 0;
}