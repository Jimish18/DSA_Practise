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

bool isValidBST(TreeNode* root) 
{
    if(!root)
    {
        return true;
    }        

    bool left = isValidBST(root->left);
    bool right = isValidBST(root->right);
    int leftcheck

    if(root->left)
    {

    }
}