/*
Question - Number of Substrings Containing All Three Characters

Link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(unordered_map<char,int> &umap)
{
    for(auto x : umap)
    {
        if(x.second == 0) return false;
    }

    return true;
}

int numberOfSubstrings(string s) 
{
    unordered_map<char,int> umap;
    int front = 0;
    int back = 0;
    int count = 0;
    int frontL = 0;
    int backL = 0;
    int n = s.size();

    while(back < n)
    {
        umap[s[back]]++;

        if(isValid(umap))
        {
            backL = n - back;
            frontL = 0;

            while(isValid(umap))
            {
                umap[s[front]]--;
                front++;
                frontL++;
            }

            count += backL*frontL;
        }

        back++;
    }

    return count;

}

int main()
{
    string s = "abc";
    cout<<numberOfSubstrings(s)<<endl;
    return 0;
}