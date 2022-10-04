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

int pathSum(TreeNode* root,int sum)
{
    if(!root)
    {
        return 0;
    }

    sum += root->val;
    int leftSum = pathSum(root->left,sum);
    
    int rightSum = pathSum(root->right,sum);
}

int maxPathSum(TreeNode* root) 
{

}

int main()
{
    return 0;
}