/*
Question - Tree Traversal

Link - https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void allTraversalInOne(BinaryTreeNode<int> *root , vector<int> &inOrder , vector<int> &preOrder , vector<int> &postOrder)
{
    if(!root) return;

    preOrder.push_back(root->data);
    allTraversalInOne(root->left,inOrder,preOrder,postOrder);
    inOrder.push_back(root->data);
    allTraversalInOne(root->right,inOrder,preOrder,postOrder);
    postOrder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result;

    if(!root) return result;    

    vector<int> inOrder;
    vector<int> preOrder;
    vector<int> postOrder;

    allTraversalInOne(root,inOrder,preOrder,postOrder);

    result.push_back(inOrder);
    result.push_back(preOrder);
    result.push_back(postOrder);

    return result;
}

int main()
{
    return 0;
}