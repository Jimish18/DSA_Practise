#include <bits/stdc++.h>
using namespace std;

// bool matchParanthesis(char c1,char c2)
// {
//     if(c1 == '(' && c2 == ')')
//     {
//         return true;
//     }
//     if(c1 == '{' && c2 == '}')
//     {
//         return true;
//     }
//     if(c1 == '[' && c2 == ']')
//     {
//         return true;
//     }

//     return false;
// }

bool isBalanced(string s)
{
    stack<char> st;
    bool res = true;

    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                res = false;
                break;
            }
        }
        else if(s[i] == '}')
        {
            if(!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                res = false;
                break;
            }
        }
        else if(s[i] == ']')
        {
            if(!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                res = false;
                break;
            }
        }
    }       

    if(!st.empty())
    {
        return false;
    }
    else
    {
        return res;
    }


}

int main()
{
    string s = "[1+{2+(20+21)}]";

    if(isBalanced(s))
    {
        cout<<"Valid string."<<endl;
    }
    else
    {
        cout<<"Invalid string."<<endl;
    }

    return 0;
}