/*
Question - Leaf - Similar Trees

Link - https://leetcode.com/problems/leaf-similar-trees/description/
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


void dfs(TreeNode* root,vector<int> &tree)
{
    if(!root) return;

    if(!root->left && !root->right) tree.push_back(root->val);

    dfs(root->left,tree);
    dfs(root->right,tree);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
    vector<int> tree1,tree2;

    dfs(root1,tree1);
    dfs(root2,tree2);

    int n = tree1.size();

    if(n != tree2.size()) return false;

    for(int i = 0 ; i < n; i++)
    {
        if(tree1[i] != tree2[i]) return false;
    }

    return true;
}