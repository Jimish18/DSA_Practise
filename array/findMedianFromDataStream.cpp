/*
Question - Find Median From Data Stream

Link - https://leetcode.com/problems/find-median-from-data-stream/
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    multiset<int> order;
    multiset<int>::iterator it;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        order.insert(num);
        if (order.size() == 1) 
        {
            it = order.begin();
        } 
        else 
        {
            if (num < *it and order.size() % 2 == 0) {
                --it;
            }
            if (num >= *it and order.size() % 2 != 0) {
                ++it;
            }
        }  
    }
    
    double findMedian() 
    {
        if (order.size() % 2 != 0) {
            return double(*it);
        } 
        else {
            auto one = *it, two = *next(it);
            return double(one + two) / 2.0;
        }
    }
};

int main()
{
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    cout<<*next(st.begin(),1)<<endl;
    return 0;
}