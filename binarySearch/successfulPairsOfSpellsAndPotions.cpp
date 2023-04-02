/*
Question - Successful Pairs of Spells and Potions

Link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
{
    int n = spells.size();
    int m = potions.size();
    vector<int> result(n);
    sort(potions.begin(),potions.end());

    for(int i = 0; i < n;i++)
    {
        int pair = 0;
        int start = 0;
        int end = m-1;
        int tempEnd = m-1;

        while(start <= tempEnd)
        {
            int mid = start + (tempEnd-start)/2;
            long long tempValue = (long long)potions[mid]*(long long)(spells[i]);

            if(tempValue >= success) tempEnd = mid-1;
            else start = mid+1;
        }

        if(end != tempEnd) pair += (end - tempEnd);
        result[i] = pair;
    }

    return result;

}

int main()
{
    return 0;
}