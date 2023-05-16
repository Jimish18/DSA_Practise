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

TreeNode* first = NULL;
TreeNode* prevPointer = NULL;
TreeNode* middle = NULL;
TreeNode* last = NULL;

void inorder(TreeNode* root)
{
    if(!root) return;

    inorder(root->left);

    if(prevPointer && (prevPointer->val > root->val))
    {
        if(!first)
        {
            first = prevPointer;
            middle = root;
        }
        else  last = root;
    }

    prevPointer = root;
    inorder(root->right);

}

void recoverTree(TreeNode* root) 
{
    prevPointer = new TreeNode(INT_MIN);
    inorder(root);

    if(first && last) swap(first->val,last->val);
    else if(first && middle) swap(first->val , middle->val);
}


int main()
{
    return 0;
}