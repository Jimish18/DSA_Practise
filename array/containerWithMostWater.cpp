/*
Question - Container With most Water

Link - https://leetcode.com/problems/container-with-most-water/
*/

#include <bits/stdc++.h>
using namespace std;

// O(n^2) Approach - TLE
// int maxArea(vector<int>& height) 
// {
//     int n = height.size();
//     int maxArea = 0;
//     int j,k;
//     int tempArea = 0;
//     for(int i = 0 ; i < n-1; i++)
//     {
//         j = i+1;
//         k = n-1;
//         tempArea = (j-i)*(min(height[j],height[i]));
//         maxArea = max(maxArea,tempArea);
//         while(j < k)
//         {
//             tempArea = (k-j)*(min(height[j],height[k]));

//             maxArea = max(maxArea,tempArea);

//             tempArea = (k-i)*(min(height[i],height[k]));
//             maxArea = max(maxArea,tempArea);
//             k--;
//         }
//     }    

//     return maxArea;    
// }

int maxArea(vector<int>& height) 
{
    int maxWater = 0;
    int i = 0,j = height.size()-1;

    while(i < j)
    {
        int h = min(height[i],height[j]);

        maxWater = max(maxWater,(j-i)*h);

        while(height[i] <= h & i < j)
        {
            i++;
        }

        while(height[j] <= h & i < j)
        {
            j--;
        }
    }  

    return maxWater;
}

int main()
{
    vector<int> v = {4,3,2,1,4};
    // {1,8,6,2,5,4,8,3,7}
    // {4,3,2,1,4}
    cout<<maxArea(v)<<endl;
    return 0;
}