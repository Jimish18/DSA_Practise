/*
Question - Subset Sums

Link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1
*/

#include <bits/stdc++.h>
using namespace std;

void calculateSubsetSums(vector<int> &result,vector<int> &ds,int index,int sum,vector<int> &arr,int &N)
{
    if(index == N)
    {
        result.push_back(sum);
        return ;
    }

    sum += arr[index];
    ds.push_back(arr[index]);
    calculateSubsetSums(result,ds,index+1,sum,arr,N);
    ds.pop_back();
    sum-= arr[index];

    calculateSubsetSums(result,ds,index+1,sum,arr,N);

}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> result;
    vector<int> ds;
    int preFixSum = 0;

    calculateSubsetSums(result,ds,0,preFixSum,arr,N);

    return result;    
}

int main()
{
    vector<int> v = {5,2,1};
    // 2,3    2
    int n = 3;
    vector<int> sumArray = subsetSums(v,n);

    for(int i = 0 ; i < sumArray.size(); i++)
    {
        cout<<sumArray[i]<<" ";
    }
    return 0;
}