/*
Question - diameter of binary Tree

Link - https://leetcode.com/problems/diameter-of-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};


int rec(TreeNode* root,int &d)
{
    if(!root) return 0;

    int ld = rec(root->left,d);
    int rd = rec(root->right,d);

    d = max(d,ld+rd);

    return max(ld,rd)+1;
}

int diameterOfBinaryTree(TreeNode* root) 
{
   int d = 0;
   rec(root,d);
   return d;     
}

int main()
{
    return 0;
}