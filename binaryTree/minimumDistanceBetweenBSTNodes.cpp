/*
Question - Minimum Distance Between BST Nodes

Link - https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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

void inOrder(TreeNode* root , vector<int> &v)
{
    if(!root) return;

    inOrder(root->left,v);
    v.push_back(root->val);
    inOrder(root->right,v);
}

int minDiffInBST(TreeNode* root) 
{
    vector<int> v;
    int result = INT_MAX;

    inOrder(root,v);
    int n = v.size();

    for(int i = 1; i < n; i++)
    {
        result = min(result,(v[i]-v[i-1]));   
    }
    
    return result;
}

int main()
{
    return 0;
}