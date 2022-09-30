/*
Question - Path Sum

Link - https://leetcode.com/problems/path-sum/
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

bool pathSum(TreeNode* root,int targerSum,int currentSum)
{
    if(!root)
    {
        return false;
    }

    currentSum += root->val;

    if(!root->left && !root->right && currentSum == targerSum)
    {
        return true;
    }

    bool leftSide = pathSum(root->left,targerSum,currentSum);
    if(leftSide)
    {
        return true;
    }
    bool rightSide = pathSum(root->right,targerSum,currentSum);

    return rightSide;
}

bool hasPathSum(TreeNode* root, int targetSum) 
{
    return pathSum(root,targetSum,0);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout<<hasPathSum(root,5)<<endl;
    return 0;
}