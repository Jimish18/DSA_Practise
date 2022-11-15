/*
Question - Longest Happy String

Link - https://leetcode.com/problems/longest-happy-string/
*/

#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c) 
{
    priority_queue<pair<int,char>> maxH;

    if(a)
    {
        maxH.push({a,'a'});
    }

    if(b)
    {
        maxH.push({b,'b'});
    }
    
    if(c)
    {
        maxH.push({c,'c'});  
    }   
    
    string result = "";

    while(maxH.size() > 1)
    {
        pair<int,char> one = maxH.top();
        maxH.pop();
        pair<int,char> two = maxH.top();
        maxH.pop();

        if(one.first >= 2)
        {
            result += one.second;
            result += one.second;
            one.first -= 2;
        }
        else
        {
            result += one.second;
            one.first -= 1;
        }

        if(two.first >= 2 && two.first >= one.first)
        {
            result += two.second;
            result += two.second;
            two.first -= 2;
        }
        else
        {
            result += two.second;
            two.first -= 1;
        }

        if(one.first > 0)
        {
            maxH.push(one);
        }

        if(two.first > 0)
        {
            maxH.push(two);
        }
    }

    if(maxH.empty())
    {
        return result;
    }

    if(maxH.top().first >= 2)
    {
        result += maxH.top().second;
        result += maxH.top().second;
    }
    else
    {
        result += maxH.top().second;
    }


    return result;
}

int main()
{
    return 0;
}