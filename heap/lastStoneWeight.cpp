/*
Question - Last Stone Weight

Link - https://leetcode.com/problems/last-stone-weight/
*/

#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) 
{
    priority_queue<int> maxH;

    for(auto x : stones)
    {
        maxH.push(x);
    }        

    while(maxH.size() > 1)
    {
        int temp1 = maxH.top();
        maxH.pop();
        int temp2 = maxH.top();
        maxH.pop();

        if(temp1 != temp2)
        {
            maxH.push(abs(temp1-temp2));
        }
    }

    return maxH.size() ? maxH.top() : 0;

}

int main()
{
    return 0;
}