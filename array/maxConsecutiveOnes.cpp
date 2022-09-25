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

}