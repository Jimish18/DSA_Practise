/*
Question - Maximum Level Sum Of A Binary Tree

Link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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

// BFS Approach
int maxLevelSum(TreeNode* root) 
{
    int maxSum = INT_MIN;
    int resultLevel ;
    queue<TreeNode*> q;
    int level = 1;

    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);  
        }
        if(maxSum < sum)
        {
            maxSum = sum;
            resultLevel = level;
        }
        level++;
    }

    return resultLevel;
    
}

int main()
{
    // Test Case 1
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(7);
    // root->right = new TreeNode(0);
    // root->left->left = new TreeNode(7);
    // root->left->right = new TreeNode(-8);

    // Test Case 2
    TreeNode* root = new TreeNode(989);
    root->right = new TreeNode(10250);
    root->left = NULL;
    root->right->left = new TreeNode(98692);
    root->right->right = new TreeNode(-89388);
    root->right->right->left = NULL;
    root->right->right->right = new TreeNode(-32127);

    cout<<maxLevelSum(root)<<endl;
    return 0;
}