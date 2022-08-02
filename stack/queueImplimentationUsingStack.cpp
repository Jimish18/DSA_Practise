/*
Question - Queue Implementation Using Stack

*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue 
{
    public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() 
    {
        
    }

    void push(int x) 
    {
        st1.push(x);
    }

    int pop() 
    {
        if(st1.empty() && st2.empty())
        {
            return -1;
        }

        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int topValue = st2.top();
        st2.pop();
        return topValue;
    }

    int peek() 
    {
        if(st1.empty() && st2.empty())
        {
            return -1;
        }

        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty() 
    {
        if(st1.empty() && st2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    cout<<obj->peek()<<endl;
    cout<<obj->empty()<<endl;
    obj->pop();
    cout<<obj->peek()<<endl;

    return 0;
}