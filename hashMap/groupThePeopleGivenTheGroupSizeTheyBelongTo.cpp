/*
Question - Group the People Given the Group Size They Belong To

There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

 

Example 1:
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Example 2:
Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
 

Constraints:
groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
{
    vector<vector<int>> result;

    unordered_map<int,vector<int>> umap;


    for(int i = 0 ; i < groupSizes.size(); i++)
    {
        umap[groupSizes[i]].push_back(i);
    }

    // for(auto i : umap)
    // {
    //     cout<<i.first<<"-> ";
    //     for(int j = 0 ; j < i.second.size(); j++)
    //     {
    //         cout<<i.second[j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> temp;

    for(auto i : umap)
    {
        for(int j = 0 ; j < i.second.size(); j++)
        {
            if(temp.size() != i.first)
            {
                temp.push_back(i.second[j]);
            }
            else
            {
                result.push_back(temp);
                temp.clear();
                temp.push_back(i.second[j]);
            }
            
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;

}

int main()
{
    vector<int > v = {2,1,3,3,3,2};
    
    for(int i = 0 ; i < groupThePeople(v).size(); i++)
    {
        for(int j = 0 ; j < groupThePeople(v)[i].size(); j++)
        {
            cout<<groupThePeople(v)[i][j]<<" ";
        }

        cout<<endl;
    }
    return 0;
}