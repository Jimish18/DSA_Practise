/*
Question - Palindrome Partitioning

Link - https://leetcode.com/problems/palindrome-partitioning/
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int start,int end)
{
    while(start <= end)
    {
        if(s[start++] != s[end--])
        {
            return false;
        }
    }

    return true;
}

void doPartition(vector<vector<string>> &result,vector<string> &ds,int index,string s)
{
    if(index == s.length())
    {
        result.push_back(ds);
        return;
    }

    for(int i = index ; i < s.length(); i++)
    {
        if(isPalindrome(s,index,i))
        {
            ds.push_back(s.substr(index,i-index+1));
            doPartition(result,ds,i+1,s);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) 
{
    vector<vector<string>> result;
    vector<string> ds;

    doPartition(result,ds,0,s);

    return result;
}

int main()
{
    
    return 0;
}