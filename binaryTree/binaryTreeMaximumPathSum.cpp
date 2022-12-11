/*
Question - Binary Tree Maximum Path Sum

Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
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

int maxSum = INT_MIN;

int pathSum(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    int leftSum = pathSum(root->left);
    int rightSum = pathSum(root->right);
    int sumLeft = max((leftSum+(root->val)+rightSum),max(leftSum+(root->val),root->val));
    int sumRight = max((leftSum+(root->val)+rightSum),max(rightSum+(root->val),root->val));

    maxSum = max(maxSum,max(sumLeft,sumRight));

    return max((leftSum+(root->val)),max(root->val,(rightSum+(root->val))));
    
}

int maxPathSum(TreeNode* root) 
{
    pathSum(root);

    return maxSum;
}

int main()
{
    return 0;
}