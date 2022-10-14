/*
Question - path Sum III

Link - https://leetcode.com/problems/path-sum-iii/
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

// Brute Force (Failed Some TestCases)
// void dfs(TreeNode* root,int targetSum,int currentSum,int &count)
// {
//     if(!root)
//     {
//         return;
//     }

//     currentSum += root->val;

//     if(currentSum == targetSum)
//     {
//         count++;
//         return;
//     }


//     dfs(root->left,targetSum,currentSum,count);
//     dfs(root->right,targetSum,currentSum,count);
// }

// void dfs2(TreeNode* root,int targetSum,int currrentSum ,int &count)
// {
//     if(!root)
//     {
//         return;
//     }
//     dfs(root,targetSum,currrentSum,count);
//     dfs2(root->left,targetSum,currrentSum,count);
//     dfs2(root->right,targetSum,currrentSum,count);
// }

// int pathSum(TreeNode* root, int targetSum) 
// {
//     int count = 0;

//     dfs2(root,targetSum,0,count);

//     return count;
// }

int dfs(TreeNode* root,long long current,int &targetSum)
{
    if(!root)
    {
        return 0;
    }

    current += root->val;

    return (current == targetSum) + dfs(root->left,current,targetSum) + dfs(root->right,current,targetSum);
}

int pathSum(TreeNode* root,int targetSum)
{
    if(!root) return 0;    

    return dfs(root,0,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
}

void inorderTraversal(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}


int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);

    // inorderTraversal(root);

    cout<<pathSum(root,8)<<endl;
    return 0;
}