/*
Question - find and replace pattern

Link - https://leetcode.com/problems/find-and-replace-pattern/
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
{
    vector<string> result;

    for(int i = 0 ; i < words.size(); i++)
    {
        map<char,char> m1;
        map<char,char> m2;
        bool flag = 1;
        
        for(int j = 0 ; j < words[i].length(); j++)
        {
            auto it1 = m1.find(pattern[j]);
            auto it2 = m2.find(words[i][j]);

            if(it1 == m1.end())
            {
                m1.insert({pattern[j],words[i][j]});
            }
            else
            {
                if(it1->second != words[i][j])
                {
                    flag = 0;
                    break;
                }
            }

            if(it2 == m2.end())
            {
                m2.insert({words[i][j],pattern[j]});
            }
            else
            {
                if(it2->second != pattern[j])
                {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag)
        {
            result.push_back(words[i]);
        }
    }

    return result;
}

int main()
{
    vector<string> v = {"a","b","c"};
    string target = "a";

    findAndReplacePattern(v,target);
    return 0;
}