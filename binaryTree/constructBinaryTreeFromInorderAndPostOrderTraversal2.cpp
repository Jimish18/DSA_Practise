/*
Question - Construct Binary Tree from Inorder and Postorder Traversal

Link - https://www.codingninjas.com/codestudio/problems/1266106?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{ 
    public:
    T data; 
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) 
    { 
        this -> data = data; 
        left = NULL; 
        right = NULL; 
    }
};

TreeNode<int>* dfs(vector<int>& postOrder, vector<int>& inOrder,int &index,int start,int end)
{
    if(start > end) return NULL;

    int pivot = start;

    while(postOrder[index] != inOrder[pivot]) pivot++;
    index--;

    TreeNode<int>* root = new TreeNode<int>()
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{

}


int main()
{
    return 0;
}