/*
Question - Invert Binary Tree

Link - https://leetcode.com/problems/invert-binary-tree/
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

void dfs(TreeNode* &root)
{
    if(!root) return ;

    dfs(root->left);
    dfs(root->right);
    TreeNode* tempLeft = root->left;
    root->left = root->right;
    root->right = tempLeft;
}

TreeNode* invertTree(TreeNode* root) 
{
   dfs(root);

   return root;    
}

int main()
{
    return 0;
}