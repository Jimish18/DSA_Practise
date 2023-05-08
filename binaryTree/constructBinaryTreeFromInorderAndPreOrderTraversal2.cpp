/*
Question - Construct Binary Tree From Inorder and Preorder Traversal

Link - https://www.codingninjas.com/codestudio/problems/920539?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
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

TreeNode<int>* dfs(vector<int> &inorder, vector<int> &preorder, int start, int end , int &index)
{
    if(start > end) return NULL;

    int point = start;

    while(preorder[index] != inorder[point]) point++;
    index++;

    TreeNode<int>* root = new TreeNode<int>(inorder[point]);

    root->left = dfs(inorder,preorder,start,point-1,index);
    root->right = dfs(inorder,preorder,point+1,end,index);

    return root;    
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int index = 0;
    return dfs(inorder,preorder,0,inorder.size()-1,index);
}


int main()
{
    return 0;
}

