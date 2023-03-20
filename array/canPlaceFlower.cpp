/*
Question - Can Place Flower

Link - https://leetcode.com/problems/can-place-flowers/
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
    int N = flowerbed.size();
    int count = 0;

    for(int i = 0; i < N && count < n; i++)
    {
        if(flowerbed[i] == 0)
        {
            int next = (i == N-1) ? 0 : flowerbed[i+1];
            int prev = (i == 0) ? 0 : flowerbed[i-1];
            if(next == 0 & prev == 0) 
            {
                flowerbed[i] = 1;
                count++;
            }
        }
    }

    return count == n;
    
}

int main()
{
    return 0;
}