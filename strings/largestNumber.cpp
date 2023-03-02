/*
Question - Largest Number

Link - https://leetcode.com/problems/largest-number/
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a,string &b)
{
    return a+b>b+a;
}

string largestNumber(vector<int>& nums) 
{
    string ans = "";

    vector<string> temp;
    for(auto x : nums)
    {
        temp.push_back(to_string(x));
    }

    sort(temp.begin(),temp.end(),cmp);

    for(auto x : temp)
    {
        ans += x;
    }
    

    return ans;
}

int main()
{
    vector<string> a = {"3","30","34","338"};
    // string s = largestNumber(a);
    sort(a.begin(),a.end(), [](string &s1,string &s2){return s1+s2>s2+s1;});

    for(auto x : a)
    {
        cout<<x<<" ";
    }
3
    return 0;
}