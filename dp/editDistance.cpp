/*
Question - Edit Distance
 
Link - https://leetcode.com/problems/edit-distance/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(string word1, string word2,int i,int j,int &result)
{
    if(i < 0 || j < 0)
    {
        if(i < 0) result += j+1;
        else if (j < 0) result += i + 1;
    
        return;
    }

    if(i == j)
    {
        if(word1[i] == word2[j])
        {
            dfs(word1,word2,i-1,j-1,result);
        }
        else
        {
            result += 1;
            result += 1 + dfs(word1,word2,i-1,j-1,result);
        }
    }
    else if(j > i)
    {
        if(word1[i] == word2[j])
        {
            result += 0 + dfs(word1,word2,i-1,j-1,result);
        }
        else
        {
            result += 1 +dfs(word1,word2,i,j-1,result);
        }
    }
    else if(j < i)
    {
        if(word1[i] == word2[j])
        {
            result += 0 + dfs(word1,word2,i-1,j-1,result);
        }
        else
        {
            result += 1 +dfs(word1,word2,i-1,j,result);
        }
    }

    return result;
}

int minDistance(string word1, string word2) 
{
    int result = 0;
    int n = word1.length();
    int m = word2.length();

    return dfs(word1,word2,n-1,m-1,result);
}

int main()
{
    return 0;
}