/*
Question - All Nodes Distance K in Binary Tree

Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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

void subTreeNode(TreeNode* root,int k, vector<int> &result)
{
    if(!root || k < 0)
    {
        return ;
    }

    if(k == 0)
    {
        result.push_back(root->val);
        return;
    }

    subTreeNode(root->left,k-1,result);
    subTreeNode(root->right,k-1,result);
}

int distanceKnode(TreeNode* root,TreeNode* target,int k,vector<int> &result) 
{
    if(!root)
    {
        return -1;
    }

    if(root == target)
    {
        subTreeNode(root,k,result);
        return 0;
    }

    int dl = distanceKnode(root->left,target,k,result);

    if(dl != -1)
    {
        if(dl+1 == k)
        {
            result.push_back(root->val);
        }
        else
        {
            subTreeNode(root->right,k-dl-2,result);
        }

        return 1+dl;
    }

    int dr = distanceKnode(root->right,target,k,result);

    if(dr != -1)
    {
        if(dr+1 == k)
        {
            result.push_back(root->val);
        }
        else
        {
            subTreeNode(root->left,k-dr-2,result);
        }

        return 1+dr;
    }
 
    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    vector<int> result;

    int k = distanceKnode(root,target,k,result);

    return result;

}

int main()
{
    return 0;
}