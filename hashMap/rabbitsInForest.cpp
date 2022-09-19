/*
Question - Rabbits in Forest

Link - https://leetcode.com/problems/rabbits-in-forest/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int numRabbits(vector<int>& answers) 
{
    ll ans=0;
    unordered_map<int,int> mp;
    for(auto i:answers){
        mp[i]++;
    }
    for(auto x:mp){
        ans += (x.second/(x.first+1)) * (x.first+1);
        if(x.second%(x.first+1)){
            ans += (x.first+1);
        }
    }
    return ans;
}

int main()
{
    return 0;
}