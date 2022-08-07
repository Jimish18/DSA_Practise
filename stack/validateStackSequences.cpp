/*
Question - Validate Stack Sequences

Given two integer arrays pushed and popped each with distinct values, return true
if this could have been the result of a sequence of push and pop operations on an
initially empty stack, or false otherwise. 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.

*/


#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    stack<int> st;

    int i = 0;
    int j = 0;

    while(i < pushed.size() && j < popped.size())
    {
        if((!st.empty()) && st.top() == popped[j])
        {
            st.pop();
            j++;
            continue;
        }

        if(pushed[i] != popped[j])
        {
            st.push(pushed[i]);
            i++;
        }        
        
        if(pushed[i] == popped[j])
        {
            i++;
            j++;
        }
    }

    while(!st.empty() && j < popped.size())
    {
        if(popped[j] == st.top())
        {
            j++;
            st.pop();
        }
        else
        {
            j++;
        }
    }

    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // vector<int> push = {1,2,3,4,5};
    // vector<int> pop = {4,3,5,1,2};

    vector<int> push = {2,3,0,1};
    vector<int> pop = {0,3,2,1};

    cout<<validateStackSequences(push,pop)<<endl;

    return 0;
}