/*
Question - Maximum Sum BST in Binary Tree

Link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
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


int maxi = 0;
class nodeDetail
{
    public:

    int minNode,maxNode,maxValue;

    nodeDetail(int minNode,int maxNode, int maxValue)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxValue = maxValue;
    }
};

nodeDetail helper(TreeNode* root)
{
    if(!root) return nodeDetail(INT_MAX,INT_MIN,0);

    auto left = helper(root->left);
    auto right = helper(root->right);

    if(left.maxNode < root->val && root->val < right.minNode)
    {
        maxi = max(maxi , left.maxValue + right.maxValue + root->val);
        return nodeDetail(min(root->val,left.minNode) , max(root->val,right.maxNode) , left.maxValue + right.maxValue + root->val);
    }

    return nodeDetail(INT_MIN,INT_MAX,max(left.maxValue,right.maxValue));
}

int maxSumBST(TreeNode* root) 
{
    maxi = 0;
    helper(root);
    return maxi;
}

int main()
{
    return 0;
}