/*
Question - Two Sum II - Input Array is Sorted 

Link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) 
{
    vector <int> result ;
    int i = 0;
    int j = numbers.size()-1;

    while(i < j)
    {
        if(numbers[i] + numbers[j] == target)
        {
            result.push_back(i+1);
            result.push_back(j+1);
            return result;
        }

        if(numbers[i] + numbers[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }  

    return result;      
}

int main()
{
    return 0;
}