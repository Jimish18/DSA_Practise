/*
Question - Kth Largest Element In a Stream

Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

#include <bits/stdc++.h>
using namespace std;


class KthLargest 
{    
    priority_queue <int, vector<int>, greater<int> > minH;
    int tempV;
    public:
    KthLargest(int k, vector<int>& nums) 
    {
        tempV = k;

        for(auto x : nums)
        {
            minH.push(x);
            while(minH.size() > tempV) minH.pop(); 
        }
    }
    
    int add(int val) 
    {
        minH.push(val);

        if(minH.size() > tempV) minH.pop();                

        return minH.top();
    }
};

int main()
{
    return 0;
}

