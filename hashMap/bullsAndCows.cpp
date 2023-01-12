/*
Question - Bulls And Cows

Link - https://leetcode.com/problems/bulls-and-cows/
*/

#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) 
{
    unordered_map<char,int> umap1,umap2;
    int bulls = 0;
    int cows = 0;

    for(int i = 0 ; i < secret.length(); i++)
    {
        umap1[secret[i]]++;
        umap2[guess[i]]++;
    }    

    for(int i = 0; i < secret.length(); i++)
    {
        if(secret[i] == guess[i])
        {
            bulls++;
            umap1[secret[i]]--;
            umap2[secret[i]]--;
        }
    }    

    for(auto x : umap1)
    {
        cows += min(x.second,umap2[x.first]);
    }

    string result = "";

    result += to_string(bulls) + 'A' + to_string(cows) + 'B';

    return result;
    
}

int main()
{
    return 0;
}