/*
Question - Lowest Common Ancestor Of Binary Tree

Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(!root)
    {
        return NULL;
    }        

    if(root == p || root == q)
    {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    if(!left && !right)
    {
        return NULL;
    }

    if(left && right)
    {
        return root;
    }

    if(left)
    {
        return left;
    }

    return right;
}

int main()
{
    return 0;
}