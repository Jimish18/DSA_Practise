/*
Question - Make Array Zero by Subtracting Equal Amounts

Link - https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
*/

#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) 
{
    unordered_set<int> st;
        
    for(int x : nums)
    {
        if(x != 0) st.insert(x);
    }
    
    return st.size();
}

int main()
{
    vector<int> v = {1,2,3,5};
    cout<<minimumOperations(v)<<endl;
    return 0;
}
