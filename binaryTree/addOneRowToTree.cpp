/*
Question - Add One Row To Tree

Link - https://leetcode.com/problems/add-one-row-to-tree/
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

TreeNode* addOneRow(TreeNode* root, int val, int depth) 
{
    if(depth == 1)
    {
        TreeNode* toReturn = new TreeNode(val);
        toReturn->left = root;
        return toReturn;
    }

    // if(!root)
    // {
    //     return new TreeNode(val);
    // }

    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    int n;

    while(!q.empty())
    {
        n = q.size();

        for(int i = 0 ; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            if(level == depth-1)
            {
                
                if(node->left)
                {
                    TreeNode* templeft = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = templeft;
                }
                else
                {
                    node->left = new TreeNode(val);
                }

                if(node->right)
                {
                    TreeNode* tempRight = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = tempRight;
                }
                else
                {
                    node->right = new TreeNode(val);
                }
                
            }
        }
        level++;
        if(level == depth)
        {
            break;
        }
    }

    return root;

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
    // TreeNode* root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(1);
    // root->right->left = new TreeNode(5);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);


    

    inorderTraversal(addOneRow(root,1,2));

    return 0;
}