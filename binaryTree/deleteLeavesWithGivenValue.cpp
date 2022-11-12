/*
Question - Delete Leaves With a Given Value

Link - https://leetcode.com/problems/delete-leaves-with-a-given-value/
*/

#include <bits/stdc++.h>
using namespace std;

TreeNode* removeLeafNodes(TreeNode* root, int target) 
{
    if(root->left) root->left = removeLeafNodes(root->left,target);
    if(root->right) root->right = removeLeafNodes(root->right,target);
    
    return root->left == root->right && root->val == target ? NULL:root;
}

int main()
{
    return 0;
}
