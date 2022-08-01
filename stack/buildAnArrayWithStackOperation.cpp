/*
Question - 
You are given an array target and an integer n.

In each iteration, you will read a number from list = [1, 2, 3, ..., n].

Build the target array using the following operations:

"Push": Reads a new element from the beginning list, and pushes it in the array.
"Pop": Deletes the last element of the array.
If the target array is already built, stop reading more elements.
Return a list of the operations needed to build target. The test cases are generated so that the answer is unique.

 

Example 1:

Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
Example 2:

Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Example 3:

Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) 
{
    stack<int> st;
    vector<string> s;

    for(int i = 0 ; i < target.size() ; i++)
    {
        st.push(target[i]);
    }

    int currentNumber = st.top();
    s.push_back("Push");
    st.pop();

    while(!st.empty())
    {
        currentNumber--;
        if(st.top() == currentNumber)
        {
            s.push_back("Push");
            st.pop();
        }
        else
        {
            s.push_back("Pop");
            s.push_back("Push");
        }
    }

    
    while(st.empty() && currentNumber > 1)
    {
        s.push_back("Pop");
        s.push_back("Push");
        currentNumber--;
    }


    vector<string> finalArray;

    for(int i = s.size()-1 ; i >= 0 ; i--)
    {
        finalArray.push_back(s[i]);
    }

    // for(int i = 0 ; i < finalArray.size(); i++)
    // {
    //     cout<<finalArray[i]<<endl;
    // }

    return finalArray;
}

int main()
{
    vector<int> v = {3,4,5,6,8,9};
    int n = 3;
    // buildArray(v,n);
    // cout<<"ji"<<endl;

    for(int i = 0 ; i < buildArray(v,n).size(); i++)
    {
        cout<<buildArray(v,n)[i]<<endl;
    }


    return 0;
}