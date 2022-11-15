/*
Question - Find K Closest Elements

Link - https://leetcode.com/problems/find-k-closest-elements/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    vector<int>  result;
    priority_queue<pair<int,int>> maxH;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        maxH.push({abs(arr[i]-x),arr[i]});

        if(maxH.size() > k)
        {
            maxH.pop();
        }
    }      

    while(!maxH.empty())
    {
        result.push_back(maxH.top().second);
        maxH.pop();
    } 

    sort(result.begin(),result.end());

    return result;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    // 1,3,5,6  2  4
    // 1,2,3,4,5  4  3
    int k = 4;
    int x = -1;
    vector<int> result = findClosestElements(v,k,x);

    for(int i = 0 ; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}