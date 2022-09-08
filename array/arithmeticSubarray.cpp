/*
Question - Arithmetic Subarray

Link - https://leetcode.com/problems/arithmetic-subarrays/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sliceSubarray(vector<int> a,int start,int end)
{
    auto startPoint = a.cbegin()+start;
    auto endPoint = a.cbegin() + end + 1;

    vector<int> result(startPoint,endPoint);
    return result;
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
{
    vector<bool> result;

    for(int i = 0 ; i < l.size(); i++)
    {
        vector<int> tempSubArray = sliceSubarray(nums,l[i],r[i]);

        sort(tempSubArray.begin(),tempSubArray.end());


        int ArithmeticDifference = tempSubArray[1]-tempSubArray[0];
        bool flag = true;
        
        for(int j = 1 ; j < tempSubArray.size(); j++)
        {
            if((tempSubArray[j]-tempSubArray[j-1]) != ArithmeticDifference)
            {
                flag = false;
                break;
            }
        }

        result.push_back(flag);
    }


    return result;
}

int main()
{
    vector<int> nums= {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vector<int> l = {0,1,6,4,8,7};
    vector<int> r = {4,4,9,7,9,10};


    for(int i = 0 ; i < l.size(); i++)
    {
        cout<<checkArithmeticSubarrays(nums,l,r)[i]<<" ";
    }

    cout<<endl;
    return 0;
}