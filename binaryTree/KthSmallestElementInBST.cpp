/*
Question - Kth Smallest Element in a BST

link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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

int dfs(TreeNode* root,int &count,int k)
{
    if(!root)
    {
        return -1;
    }

    int left = dfs(root->left,count,k);
    count++;
    if(count == k)
    {
        return root->val;
    }
    int right = dfs(root->right,count,k);

    return (left != -1) ? left : right;
}

int kthSmallest(TreeNode* root, int k) 
{
    int count = 0;
    return dfs(root,count,k);
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    cout<<kthSmallest(root,4)<<endl;
    return 0;
}