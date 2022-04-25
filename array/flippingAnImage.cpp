/*
Problem Statement :->
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 

Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]


Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
        for(int i = 0 ; i < image.size() ; i++)
        {
            for(int j = 0 ; j < (image[i].size()/2) ; j++)
            {
                int temp = image[i][j];
                image[i][j] = image[i][image[i].size()-1-j];
                image[i][image[i].size()-1-j] = temp;
            }
        }

        for(int i = 0 ; i < image.size() ; i++)
        {
            for(int j = 0 ; j < image[i].size() ; j++)
            {
                if(image[i][j] == 1)
                {
                    image[i][j] = 0;
                }
                else
                {
                    image[i][j] = 1;
                }
            }
        }

        return image;
    }
};

int main()
{
    int n = 3;

    vector<vector<int>> v;
    for(int i = 0 ; i < n ; i++)
    {
        vector<int> temp;
        for(int j = 0 ; j < n ; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }

        v.push_back(temp);
    }

    Solution sol;
    sol.flipAndInvertImage(v);

    // for(int i = 0 ; i < n ; i++)
    // {
    //     for(int j = 0 ; j < (v[i].size()/2) ; j++)
    //     {
    //         int temp = v[i][j];
    //         v[i][j] = v[i][v[i].size()-1-j];
    //         v[i][v[i].size()-1-j] = temp;
    //     }
    // }

    // for(int i = 0 ; i < v.size() ; i++)
    // {
    //     for(int j = 0 ; j < v[i].size() ; j++)
    //     {
    //         if(v[i][j] == 1)
    //         {
    //             v[i][j] = 0;
    //         }
    //         else
    //         {
    //             v[i][j] = 1;
    //         }
    //     }
    // }

    // for(int i = 0 ; i < v.size() ; i++)
    // {
    //     for(int j = 0 ; j < v[i].size() ; j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }        
    //     cout<<endl;
    // }
    
    return 0;
}