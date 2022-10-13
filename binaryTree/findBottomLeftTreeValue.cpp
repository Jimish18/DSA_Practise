/*
Question - Find Bottom Left Tree Value

Link - https://leetcode.com/problems/find-bottom-left-tree-value/
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

int findBottomLeftValue(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    int n;

    while(!q.empty())
    {
        n = q.size();

        for(int i = 0 ; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);

            if(q.empty())
            {
                return node->val;
            }
        }
    }

    return -1;
}

int main()
{
    return 0;
}