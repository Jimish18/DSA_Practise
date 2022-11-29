/*
Question - Insert Delete GetRandom O(1)

Link - https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet 
{
    public:
    unordered_set<long long> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(st.find(val) != st.end())
        {
            return false;
        }    
        else
        {
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) 
    {
        if(st.find(val) != st.end())
        {
            st.erase(val);
            return true;
        }    
        else
        {
            return false;
        }
    }
    
    int getRandom() 
    {
        long long n = st.size();   
        long long random = rand()%n;
        auto it = st.begin();
        advance(it,random);

        return (*it);
    }
};

int main()
{
    return 0;
}