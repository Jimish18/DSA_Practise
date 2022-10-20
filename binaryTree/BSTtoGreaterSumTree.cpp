/*
Question - BST to Greater Sum Tree

Link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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


int pre = 0;
TreeNode* bstToGst(TreeNode* root) 
{
    if(root->right) bstToGst(root->right);
    root->val += pre;

    pre = root->val;

    if(root->left) bstToGst(root->left);

    return root;
}

int main()
{
    return 0;
}