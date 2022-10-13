/*
Question - Even Odd Tree

Link - https://leetcode.com/problems/even-odd-tree/
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

bool isEvenOddTree(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    int n;
    int inc = INT_MIN;
    int dec = INT_MAX;
    bool result = true;
    int level = 0;

    while(!q.empty())
    {
        n = q.size();
        for(int i = 0 ; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            if(level%2 == 0)
            {
                if((node->val)%2 != 0)
                {
                    if(node->val > inc)
                    {
                        inc = node->val;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if((node->val)%2 == 0)
                {
                    if(node->val < dec)
                    {
                        dec = node->val;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        inc = INT_MIN;
        dec = INT_MAX;
        level++;
    }

    return result;        
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(2);

    cout<<isEvenOddTree(root)<<endl;
    return 0;
}