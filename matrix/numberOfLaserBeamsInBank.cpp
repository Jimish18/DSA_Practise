/*
Question - Number of Laser Beams in a Bank

Link - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank) 
{
    int n = bank.size();
    int m = bank[0].size();
    vector<int> securityDevice;
    int rowDevice = 0;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(bank[i][j] == '1')
            {
                rowDevice++;
            }
        }
        if(rowDevice > 0)
        {
            securityDevice.push_back(rowDevice);
        }
        rowDevice = 0;
    }

    if(securityDevice.size() <= 1)
    {
        return 0;
    }

    int count = 0;

    for(int i = 1 ; i < securityDevice.size(); i++)
    {
        count += securityDevice[i]*securityDevice[i-1];
    }

    return count;

    
}

int main()
{
    vector<string> bank = {"000","111","000"};
    cout<<numberOfBeams(bank)<<endl;
    return 0;
}