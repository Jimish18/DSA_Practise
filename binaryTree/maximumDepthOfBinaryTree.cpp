/*
Question - Maximum Depth of Binary Tree

Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

int maxDepth(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    }
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}