/*
Question - Insert Into A Binary Search Tree

Link - https://leetcode.com/problems/insert-into-a-binary-search-tree/
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

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(!root) return new TreeNode(val);

    TreeNode* temp = root;

    while(temp)
    {
        if(temp->val > val)
        {
            if(!temp->left) 
            {
                temp->left = new TreeNode(val);
                return root;
            }
            temp = temp->left;
        }
        else
        {
            if(!temp->right)
            {
                temp->right = new TreeNode(val);
                return root;
            }
            temp = temp->right;
        }
    }

    return root;
}

int main()
{
    return 0;
}