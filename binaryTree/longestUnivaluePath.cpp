/*
Question - Longests Univalue Path

Link - https://leetcode.com/problems/longest-univalue-path/
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

pair<int,int> dfs(TreeNode* root,int &maximum)
{
    if(!root)
    {
        return {-1001,0};
    }

    pair<int,int> left = dfs(root->left,maximum);
    pair<int,int> right = dfs(root->right,maximum);

    if(root->val == left.first)
    {
        
    }

}

int longestUnivaluePath(TreeNode* root) 
{
        
}

int main()
{
    return 0;
}