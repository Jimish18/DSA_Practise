/*
Question - validate Binary Search Tree

link - https://leetcode.com/problems/validate-binary-search-tree/
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

bool dfs(TreeNode* root,long min,long max)
{
    if(!root) return true;

    if(root->val <= min || root->val >= max) return false;

    return dfs(root->left,min,root->val) && dfs(root->right,root->val,max);
}

bool isValidBST(TreeNode* root) 
{
    return dfs(root,LONG_MIN,LONG_MAX);
}