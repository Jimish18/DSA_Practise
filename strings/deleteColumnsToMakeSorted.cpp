/*
Question - Delete Columns To Make Sorted

Link - https://leetcode.com/problems/delete-columns-to-make-sorted/
*/

#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) 
{
    int n = strs.size();
    int m = strs[0].length();
    int count;

    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(strs[j][i] < strs[j-1][i])
            {
                count++;
                break;
            }
        }        
    }   

    return count;     
}

int main()
{
    return 0;
}