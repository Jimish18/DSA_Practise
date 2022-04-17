#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;

    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top(); //top will be operand 2
            st.pop();
            int op1 = st.top(); //2nd top will be operand 1
            st.pop();

            switch (s[i])
            {
            
                case '+':
                    st.push(op1+op2);
                    break;

                case '-':
                    st.push(op1-op2);
                    break;

                case '*':
                    st.push(op1*op2);
                    break;

                case '/':
                    st.push(op1/op2);
                    break;

                case '^':
                    st.push(pow(op1,op2));
                    break;

            }
        }
    }

    return st.top();
}

int main()
{
    string s = "745*+20+-";
    // string s = "46+2/5*7+";
    cout<<prefixEvaluation(s)<<endl;
    return 0;
}