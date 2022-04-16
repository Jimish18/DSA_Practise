#include <bits/stdc++.h>
using namespace std;
 
void reverseSentense(string s)
{
    stack<string> st;
    string word;
    for(int i = 0 ; i < s.length() ; i++)
    {
        word = "";

        while(s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    cout<<"Reversed String :"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string s = "hey, how are you doing?";

    cout<<"Original String :"<<endl<<s<<endl<<endl;


    reverseSentense(s);

    return 0;
}