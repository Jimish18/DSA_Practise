/*
Question - Top K Frequent Words


Link - https://leetcode.com/problems/top-k-frequent-words/
*/

#include <bits/stdc++.h>
using namespace std;


class myComparator {
  public:
    bool operator() (const pair<int,string> &p1, const pair<int,string> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) 
{
    unordered_map<string,int> umap;
    priority_queue<pair<int,string>,vector<pair<int,string>>,myComparator> minH;
    int n = words.size();
    vector<string> result(k);

    for(int i = 0; i < n; i++)
    {
        umap[words[i]]++;
    }

    for(auto x : umap)
    {
        minH.push({x.second,x.first});

        if(minH.size() > k)
        {
            minH.pop();
        }
    }

    int m = k-1;

    while(minH.size() > 0)
    {
        result[m--] = minH.top().second;
        minH.pop();
    }

    return result;    
}

int main()
{
    vector<string> v = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    // {"the","day","is","sunny","the","the","the","sunny","is","is"}
    // {"i","love","leetcode","i","love","coding"}
    int k = 4;
    vector<string> result = topKFrequent(v,k);

    for(string x : result)
    {
        cout<<x<<endl;
    }
    return 0;
}