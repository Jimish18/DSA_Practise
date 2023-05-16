/*
Question - Recover BST

Link - https://leetcode.com/problems/recover-binary-search-tree/
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

vector<long long> inorderList;

void inorder(TreeNode* root)
{
    if(!root) return;

    inorder(root->left);
    inorderList.push_back(root->val);
    inorder(root->right);
}

void recover(TreeNode* &root,int &index)
{
    if(!root) return;

    recover(root->left,index);
    root->val = inorderList[index++];
    recover(root->right,index);
}

void recoverTree(TreeNode* root) 
{
    inorder(root);
    sort(inorderList.begin(),inorderList.end());
    int index = 0;
    recover(root,index);

}

int main()
{
    return 0;
}