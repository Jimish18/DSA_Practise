/*
Question - Minimum Absolute Difference In BST

Link - https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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

int minDiff = INT_MAX;
int minValue = -1;

void dfs(TreeNode* &root)
{
    if(root->left) dfs(root->left);

    if(minValue >= 0) minDiff = min(minDiff , root->val - minValue);

    minValue = root->val;

    if(root->right) dfs(root->right);
}

int getMinimumDifference(TreeNode* root) 
{
    dfs(root);
    return minDiff;
}
int main()
{
    return 0;
}