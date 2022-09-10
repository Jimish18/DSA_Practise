/*
Question - Longest Consequitive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    if(nums.size() == 0)
    {
        return 0;
    }

    unordered_set<int> st(nums.begin(),nums.end());

    int maxLength = 0;
    int length = 0;

    for(auto i : st)
    {
        int temp = i;

        if(st.find(temp-1) == st.end())
        {
            length++;
            while(st.find(temp + 1) != st.end())
            {
                length++;
                temp++;
            }
        }

        maxLength = max(maxLength,length);
        length = 0;
    }

    return maxLength;

}

int main()
{
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};

    cout<<longestConsecutive(v)<<endl;
    return 0;
}