/*
Question - Longest Zigzag Path in a Binary Tree

Link - https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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

int maxLength = 0;

void dfs(TreeNode* root,int dir, int length)
{
    if(!root) return;

    maxLength = max(maxLength,length);

    dfs(root->left, 0 , dir ? 1+length : 1);
    dfs(root->right, 1 , dir ? 1 : 1+length);

}

int longestZigZag(TreeNode* root) 
{
    dfs(root,0,0);
    dfs(root,1,0);

    return maxLength;
}

int main()
{
    return 0;
}