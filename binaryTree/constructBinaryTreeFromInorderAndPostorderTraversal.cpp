/*
Question - Construct Binary Tree from Inorder and Postorder Traversal

Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int &index,int left,int right)
{
    if(left > right) return NULL;

    int pivot = left;

    while(inorder[pivot] != postorder[index]) pivot++;

    index--;

    TreeNode* root = new TreeNode(inorder[pivot]);

    root->right = helper(inorder,postorder,index,pivot+1,right);
    root->left = helper(inorder,postorder,index,left,pivot-1);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    int index = postorder.size()-1;
    
    return helper(inorder,postorder,index,0,postorder.size()-1);        
}

int main()
{
    return 0;
}