/*
Question - max Consecutive ones III

Link - https://leetcode.com/problems/max-consecutive-ones-iii/
*/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int j = 0;
    int numberOfZeros = 0;
    int maxNumberOfOnes = INT_MIN;
    int n = nums.size();

    for(int i = 0 ; i < n; i++)
    {
        if(nums[i] == 0)
        {
            numberOfZeros++;
        }
        while(numberOfZeros > k)
        {
            if(nums[j] == 0)
            {
                numberOfZeros--;
            }
            j++;
        }
        maxNumberOfOnes = max(maxNumberOfOnes,i-j+1);
    }    

    return maxNumberOfOnes;
}

int main()
{
    vector<int> v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    // 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1
    // 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
    cout << longestOnes(v, 3) << endl;
    return 0;
}