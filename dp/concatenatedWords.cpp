/*
Question - Concatenated Words

Link - https://leetcode.com/problems/concatenated-words/description/
*/

#include <bits/stdc++.h>
using namespace std;

bool concat_possible(string &word,vector<string>& words, unordered_map<string,int>&mp)
{
    int size=word.size();
    for(int i=1;i<size;++i)
    { 
        string prefix=word.substr(0,i);
        string suffix=word.substr(i);  
        if(mp[prefix] && (mp[suffix] || concat_possible(suffix,words,mp)))
        {   
            return true;
        }
    }
    return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
{
    vector<string>ans;
    unordered_map<string,int>mp; 
    for(auto string:words)
    {   
        mp[string]++;
    }

    for(auto &word:words)
    {  
        if(concat_possible(word,words,mp))
        {
            ans.push_back(word);
        }
    }
    return ans;
}

int main()
{
    return 0;
}