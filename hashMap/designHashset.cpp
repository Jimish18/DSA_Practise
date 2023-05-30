/*
Question - Design Hashset

Link - https://leetcode.com/problems/design-hashset/description/
*/

#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    unordered_set<int> uSet;
    MyHashSet() {
        
    }
    
    void add(int key) {
        uSet.insert(key);
    }
    
    void remove(int key) 
    {
        uSet.erase(key);
    }
    
    bool contains(int key) {
        if(uSet.find(key) != uSet.end()) return true;

        return false;
    }
};

int main()
{
    return 0;
}