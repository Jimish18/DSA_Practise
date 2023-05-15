/*
Question - LCA Of a BST

Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(!root) return NULL;

    TreeNode* temp = root;

    while(temp)
    {
        if(temp->val < p->val && temp->val < q->val) temp = temp->right;        
        else if(temp->val > p->val && temp->val > q->val) temp = temp->left;
        else return temp;
    }   

    return temp;
}

int main()
{
    return 0;
}