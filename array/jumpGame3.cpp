/*
Question - Jump Game III

Link - https://leetcode.com/problems/jump-game-iii/
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& arr, int index,vector<bool> &visited)
{
    if(index > arr.size()-1 || index  < 0) return false;
    
    if(arr[index] == 0) return true;

    if(!visited[index])
    {
        visited[index] = true;
        return (dfs(arr,index+arr[index],visited) || dfs(arr,index-arr[index],visited));
    } 

    return false;
}

bool canReach(vector<int>& arr, int start) 
{
    int n = arr.size();
    vector<bool> visited(n,false);
    return dfs(arr,start,visited);
}
int main()
{
    return 0;
}