/*
Question - Sum of Nodes with Even-Valued Grandparent

Link - https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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

int ans = 0;
void sumCalculate(TreeNode* root)
{
    if(root->left)
    {
        if(root->left->left)
        {
            ans += root->left->left->val;
        }

        if(root->left->right)
        {
            ans += root->left->right->val;
        }
    }

    if(root->right)
    {
        if(root->right->left)
        {
            ans += root->right->left->val;
        }

        if(root->right->right)
        {
            ans += root->right->right->val;
        }  
    }
}

void dfs(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    if(root->val%2 == 0)
    {
        sumCalculate(root);
    }

    if(root->left)
    {
        dfs(root->left);
    }

    if(root->right)
    {
        dfs(root->right);
    }

}

int sumEvenGrandparent(TreeNode* root) 
{
    if(!root || (!root->left && !root->right))
    {
        return 0;
    }
    ans = 0;
    dfs(root);  

    return ans;

}

int main()
{
    return 0;
}