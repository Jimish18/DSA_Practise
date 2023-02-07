/*
Question - Fruits into Baskets


Link - https://leetcode.com/problems/fruit-into-baskets/
*/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) 
{
    unordered_map<int,int> umap;
    int n = fruits.size();
    int result = INT_MIN;

    int i = 0 , j = 0;

    while(j < n)
    {        
        umap[fruits[j]]++;

        if(umap.size() <= 2) result = max(result,j-i+1);
        else 
        {
            umap[fruits[i]]--;

            if(umap[fruits[i]] == 0) umap.erase(fruits[i]);

            i++;
        }

        j++;
    }

    return result;

}

int main()
{
    return 0;
}