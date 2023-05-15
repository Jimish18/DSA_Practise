/*
Question - Kth Largest Element In BST

Link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

int dfs(Node* &root, int &count , int k)
{
    if(!root) return -1;

    int right = dfs(root->right,count,k);

    count++;

    if(count == k) return root->data;

    int left = dfs(root->left,count,k);

    return (right != -1) ? right : left;
}

int kthLargest(Node *root, int K)
{
    int count = 0;
    return dfs(root,count,k);
}

int main()
{
    return 0;
}