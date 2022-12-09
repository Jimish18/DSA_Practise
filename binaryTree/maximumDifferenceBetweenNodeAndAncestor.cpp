/*
Question - Maximum Difference Between Node and Ancestor

Link - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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

int diff = INT_MIN;

void dfs2(TreeNode* root,int value)
{
    if(!root) return; 

    int tempDiff = abs((root->val) - value);

    diff = max(diff,tempDiff);
    cout<<diff<<endl;
    dfs2(root->left,value);
    dfs2(root->right,value);
}

void dfs(TreeNode* root)
{
    if(!root) return;

    dfs2(root,root->val);
    dfs(root->left);
    dfs(root->right);
}

int maxAncestorDiff(TreeNode* root) 
{
    return diff;
}





int main()
{
    return 0;
}