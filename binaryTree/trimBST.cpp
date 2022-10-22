/*
Question - Trim a Binary Search Tree

Link - https://leetcode.com/problems/trim-a-binary-search-tree/
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

TreeNode* trimBST(TreeNode* root, int low, int high) 
{
        
}

int main()
{

    return 0;
}