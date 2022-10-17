/*
Question - Check if the sentence is pangram

Link - https://leetcode.com/problems/check-if-the-sentence-is-pangram/
*/

#include <bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence) 
{
    int n = sentence.length();
    
    if(n < 26)
    {
        return false;
    }
    
    unordered_set<char> st;
    
    for(int i = 0; i < n; i++)
    {
        st.insert(sentence[i]);
    }
    
    return (st.size() == 26) ? true : false;
}

int main()
{
    return 0;
}