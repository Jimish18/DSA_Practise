/*
Question - Online Stock Span

Link - https://leetcode.com/problems/online-stock-span/
*/

#include <bits/stdc++.h>
using namespace std ;

class StockSpanner 
{
    public:
    stack<pair<int,int>> st;    
    StockSpanner() 
    {

    }
    
    int next(int price) 
    {
        int days = 1;
        while(!st.empty() && st.top().first <= price)
        {
            days += st.top().second;
            st.pop();
        }  
        st.push({price,days});

        return days;
    }
};

int main()
{
    StockSpanner* s = new StockSpanner();

    vector<int> v = {100,80,60,70,60,75,85};
    vector<int> stockSpan;

    for(int i = 0 ; i < v.size(); i++)
    {
        stockSpan.push_back(s->next(v[i]));
    }

    for(int i = 0 ; i < stockSpan.size(); i++)
    {
        cout<<stockSpan[i]<<" ";
    }
    return 0;
}