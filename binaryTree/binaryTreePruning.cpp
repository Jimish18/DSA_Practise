/*
Question - Binary Tree Pruning

Link - https://leetcode.com/problems/binary-tree-pruning/
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

void dfs(TreeNode* root)
{    
    if(!root)
    {
        return;
    }
    
    if(!root->left && !root->right)
    {
        return ;
    }     

    dfs(root->left);
    dfs(root->right);

    if(root->left)
    {
        if(root->left->val == 0 && !root->left->left && !root->left->right)
        {        
            root->left = NULL;
        } 
    }
    if(root->right)
    {
        if(root->right->val == 0 && !root->right->left && !root->right->right)
        {
            root->right = NULL;
        } 
    }
}

TreeNode* pruneTree(TreeNode* root) 
{        
    dfs(root);
    
    if(!root->left && !root->right && root->val == 0)
    {
        return NULL;
    }
    return root;
}

void inorderTraversal(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    // root->right = new TreeNode(0);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(1);
    

    inorderTraversal(root);

    cout<<endl;

    inorderTraversal(pruneTree(root));


    return 0;
}