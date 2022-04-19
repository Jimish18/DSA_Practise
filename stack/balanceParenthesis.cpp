#include <bits/stdc++.h>
using namespace std;

bool matchParanthesis(char c1,char c2)
{
    if(c1 == '(' && c2 == ')')
    {
        return true;
    }
    if(c1 == '{' && c2 == '}')
    {
        return true;
    }
    if(c1 == '[' && c2 == ']')
    {
        return true;
    }

    return false;
}

bool isBalanced(string s)
{
    stack<char> st;

    for(int i = 0 ; i < s.length(); i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            continue;
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            continue;
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(st.empty())
            {
                return false;
            }
            if(matchParanthesis(st.top(),s[i]))
            {
                st.pop();
            }
        }
        else if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            continue;
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
    string s = "[1+{(2+3)-(12-25)}]";

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