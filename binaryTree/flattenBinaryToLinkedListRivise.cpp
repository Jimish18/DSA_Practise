/*
Question - Flatten Binary To Linked List Revise

Link - https://www.codingninjas.com/codestudio/problems/flatten-binary-tree-to-linked-list_1112615?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void dfs(TreeNode<int>* &root)
{
    if(!root) return;

    if(!root->left && !root->right) return;


    if(root->left)
    {
        dfs(root->left);

        TreeNode<int>* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        TreeNode<int>* t = root->right;

        while(t->right) t = t->right;

        t->right = temp;
    }

    dfs(root->right);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    dfs(root);

    return root;
}

int main()
{
    return 0;
}

