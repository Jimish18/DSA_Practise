/*
Question - Smallest Number in Infinite Set

Link - https://leetcode.com/problems/smallest-number-in-infinite-set/
*/

#include <bits/stdc++.h>
using namespace std;


class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue<int,vector<int>,greater<int>> minH;
    unordered_set<int>::iterator it;
    
    SmallestInfiniteSet() {
       for(int i = 1 ; i <= 1000; i++)
    {
        st.insert(i);
        minH.push(i);
    } 
    }
    
    int popSmallest() 
    {
        it = st.find(minH.top());
        st.erase(it);
        int toPop = minH.top();
        minH.pop();
        
        return toPop;
    }
    
    void addBack(int num) 
    {
        if(st.find(num) == st.end())
        {
            st.insert(num);
            minH.push(num);
        }
    }
};

int main()
{
    return 0;
}