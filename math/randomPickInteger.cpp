/*
Question - Random Pick Integer

Link - https://leetcode.com/problems/random-pick-index/description/
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> temp;

    Solution(vector<int>& nums) 
    {
        temp = nums;    
    }
    
    int pick(int target) 
    {
        int n = temp.size();
        int random = 0 + (rand()%n);

        while(temp[random] != target)
        {
            random = 0 + (rand()%n);
        }    

        return random;
    }
};


int main()
{
    return 0;
}