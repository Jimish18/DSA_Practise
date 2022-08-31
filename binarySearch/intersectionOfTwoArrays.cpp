/*
Question - Intersection Of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.


Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

void intersection(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int > res;
    unordered_map<int,int> umap;
    

    sort(nums1.begin(),nums1.end());

    for(int i = 0 ; i < nums1.size(); i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    sort(nums2.begin(),nums2.end());

    if(nums1.size() > nums2.size())
    {
        int i = 0;
        
        while(i < nums2.size())
        {
            int s = 0;
            int e = nums1.size();
            int n = nums2.size();
            int m = s + (e-s)/2;

            while(s <= e)
            {
                if(nums1[m] == nums2[i])
                {
                    if(umap[nums1[m]] < 1)
                    {
                        umap[nums1[m]]++;
                    }
                }
                
                if(nums1[m] < nums2[i])
                {
                    s = (m+1)%n;
                }
                else
                {
                    e = (m+n-1)%n;
                }

                m = s + (e-s)/2;
            }
        }

        i++;
    }    
    else
    {
        int i = 0;
        
        while(i < nums1.size())
        {
            int s = 0;
            int e = nums2.size();
            int n = nums1.size();
            int m = s + (e-s)/2;

            while(s <= e)
            {
                if(nums2[m] == nums1[i])
                {
                    if(umap[nums2[m]] < 1)
                    {
                        umap[nums2[m]]++;
                    }
                }
                
                if(nums2[m] < nums1[i])
                {
                    s = (m+1)%n;
                }
                else
                {
                    e = (m+n-1)%n;
                }

                m = s + (e-s)/2;
            }
        }

        i++;
    } 

    // for(auto i : umap)
    // {
    //     cout<<i.first<<" ";
    // }
    // cout<<endl;
    

    

    // return res; 
}

int main()
{
    vector<int > nums1 = {4,9,5};
    vector<int > nums2 = {9,4,9,8,4};

    intersection(nums1,nums2);

    return 0;
}