/*
Question - Mirror Tree

Link - https://practice.geeksforgeeks.org/problems/mirror-tree/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

void dfs(Node* &node)
{
    if(!node) return;

    dfs(node->left);
    dfs(node->right);

    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void mirror(Node* node) 
{
    dfs(node);
}


int main()
{
    return 0;
}