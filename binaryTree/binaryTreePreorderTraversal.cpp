/*
Question - Binary Tree PreOrder Traversal

Link - https://leetcode.com/problems/binary-tree-preorder-traversal/
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

void preOrderDfs(TreeNode* root,vector<int> &result)
{
    if(!root) return;

    result.push_back(root->val);
    preOrderDfs(root->left,result);
    preOrderDfs(root->right,result);
}

vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int> result;
    preOrderDfs(root,result);
    return result;
}

int main()
{
    return 0;
}