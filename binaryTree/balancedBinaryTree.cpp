/*
Question - Balanced Binary Tree

Link - https://leetcode.com/problems/balanced-binary-tree/
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

int heightOfBinaryTree(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    return max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right)) + 1;
}

bool isBalanced(TreeNode* root) 
{
    if(!root)
    {
        return true;
    }

    if(!isBalanced(root->left))
    {
        return false;
    }
    if(!isBalanced(root->right))
    {
        return false;
    }

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    if(abs(leftHeight - rightHeight) <= 1)
    {
        return true;
    }
    
    return false;

}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    cout<<isBalanced(root)<<endl;
    return 0;
}