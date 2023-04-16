/*
Question - Vertical Order Traversal of a Binary Tree

Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

map<int,map<int,vector<int>>> umap;

void dfs(TreeNode* root,int vLevel,int hLevel)
{
    if(!root) return ;

    umap[vLevel][hLevel].push_back(root->val);

    dfs(root->left,vLevel-1,hLevel+1);
    dfs(root->right,vLevel+1,hLevel+1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    vector<vector<int>> result; 

    dfs(root,0,0);

    for(auto x : umap)
    {
        vector<int> temp;
        for(auto y : x.second)
        {
            sort(y.second.begin(),y.second.end());
            for(auto z : y.second)
            {
                temp.push_back(z);
            }
        }

        result.push_back(temp);
    }

    return result;
}


int main()
{
    return 0;
}