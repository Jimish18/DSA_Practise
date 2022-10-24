/*
Question - Balance a Binary Search Tree

Link -https://leetcode.com/problems/balance-a-binary-search-tree/
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

void inorderTraversal(TreeNode* root,vector<int> &inorder)
{
    if(!root)
    {
        return;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right,inorder);

}

TreeNode* buildBalanceBST(vector<int> &inorder,int left,int right)
{
    if(left > right)
    {
        return NULL;
    }

    int mid = right - (right - left)/2;

    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = buildBalanceBST(inorder,left,mid-1);
    root->right = buildBalanceBST(inorder,mid+1,right);

    return root;
}

TreeNode* balanceBST(TreeNode* root) 
{
    vector<int> inorder;
    inorderTraversal(root,inorder);

    TreeNode* root2 = buildBalanceBST(inorder,0,inorder.size());

    return root2;
}



int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode* newRoot = balanceBST(root);
    return 0;
}