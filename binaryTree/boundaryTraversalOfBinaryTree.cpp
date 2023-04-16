/*
Question - Boundary Traversal of Binary Tree

Link - https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;\

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool isLeaf(TreeNode<int>* root)
{
    if(!root->left && !root->right) return true;

    return false;
}

void addLeftBoundary(TreeNode<int>* root,vector<int> &result)
{
    TreeNode<int>* temp = root->left;

    while(temp)
    {
        if(!isLeaf(temp)) result.push_back(temp->data);
        if(temp->left) temp = temp->left;
        else temp = temp->right;
    }
}

void addRightBoundary(TreeNode<int>* root,vector<int> &result)
{
    TreeNode<int>* temp = root->right;
    vector<int> tempArray;

    while(temp)
    {
        if(!isLeaf(temp)) tempArray.push_back(temp->data);
        if(temp->right) temp = temp->right;
        else temp = temp->left;
    }

    for(int i = tempArray.size()-1 ; i >= 0; i--)
    {
        result.push_back(tempArray[i]);
    }
}

void addLeafBoundary(TreeNode<int>* root,vector<int> &result)
{
    if(isLeaf(root))
    {
        result.push_back(root->data);
        return;
    }

    if(root->left) addLeafBoundary(root->left,result);
    if(root->right) addLeafBoundary(root->right,result);
}

vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int> result;

    if(!root) return result;
    if(!isLeaf(root)) result.push_back(root->data);

    addLeftBoundary(root,result);
    addLeafBoundary(root,result);
    addRightBoundary(root,result);

    return result;
}

int main()
{
    

    return 0;
}