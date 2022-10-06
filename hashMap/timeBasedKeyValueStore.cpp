/*
Question - Time Based Key-value Stored

Link - https://leetcode.com/problems/time-based-key-value-store/
*/

#include <bits/stdc++.h>
using namespace std;

class TimeMap 
{   
    unordered_map<string,map<int,string>> umap;
    public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        umap[key].insert({timestamp,value});  
    }
    
    string get(string key, int timestamp) 
    {
        auto it = umap[key].upper_bound(timestamp);
        if(it == umap[key].begin())
        {
            return "";
        }  
        it--;
        return it->second; 
    }
};

int main()
{
    return 0;
}