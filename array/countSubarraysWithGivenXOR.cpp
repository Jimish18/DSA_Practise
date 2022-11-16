/*
Question - Count Subarrays with Given XOR

link - 
*/

#include <bits/stdc++.h>
using namespace std;

// native Brute Force Approach O(N^2) O(1)
// int subarraysXor(vector<int> &arr, int x)
// {
//     int count = 0;
//     int n = arr.size();

//     for(int i = 0 ; i < n; i++)
//     {
//         int exor = arr[i];

//         if(exor == x) count++;
//         for(int j = i+1; j < n; j++)
//         {
//             exor = exor^arr[j]; 
//             if(exor == x) count++;
//         }
//     }

//     return count;
// }

// Optimized Approach O(N) O(N)
int subarraysXor(vector<int> &arr, int x)
{
    int count = 0;
    unordered_map<int,int> umap;
    int cpx = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        cpx ^= arr[i];

        if(cpx == x) count++;
        
        int h = cpx^x;

        if(umap.find(h) != umap.end())
        {
            count += umap[h];
        }

        umap[cpx]++;
    }

    return count;
}

int main()
{
    vector<int> v = {5,2,9};
    // 5,3,8,3,10   8

    int exor = 7;
    // cout<<subarraysXor(v,exor)<<endl;

    cout<<(4^6)<<endl;
    return 0;
}
