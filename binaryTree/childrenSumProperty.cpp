/*
Question - Children Sum Property

Link - https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode < T > *left;
    BinaryTreeNode < T > *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void dfs(BinaryTreeNode < int > * &root)
{
    if(!root) return;

    int child = 0;

    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child < root->data)
    {
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    dfs(root->left);
    dfs(root->right);

    int temp = 0;
    if(root->left) temp += root->left->data;
    if(root->right) temp += root->right->data;
    if(root->left || root->right) root->data = temp;
    
}

void changeTree(BinaryTreeNode < int > * root) 
{
    dfs(root);
}  


int main()
{
    return 0;
}