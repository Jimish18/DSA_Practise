#include <bits/stdc++.h>
using namespace std;
#define n 100

class Stack
{
    int* array;
    int top;

    public:

    Stack()
    {
        array = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if(top == n-1)
        {
            cout<<"stack OverFlow"<<endl;
            return;
        }
        else
        {
            top++;
            array[top] = x;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        else
        {
            top--;
        }
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return array[top];
    }

    bool empty()
    {
        return top==-1;
    }
};