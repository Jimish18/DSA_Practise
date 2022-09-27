/*
Question - Minimum Depth Of Binary Tree

Link - https://leetcode.com/problems/minimum-depth-of-binary-tree/
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

// DFS Approach
// void minimumDepth(TreeNode* root,int &minD,int d)
// {
//     if(!root->left && !root->right) 
//     {
//         minD = min(minD,d);
//         return;
//     }
//     d++;
//     if(root->left) 
//     {
//         minimumDepth(root->left,minD,d);
//     }
//     if(root->right) 
//     {
//         minimumDepth(root->right,minD,d);
//     }
// }

// int minDepth(TreeNode* root)
// {
//     if(root==NULL) return 0;
//     int minD = INT_MAX;
//     int d = 1;
//     minimumDepth(root,minD,d);

//     return minD;
// }

int minDepth(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    queue<TreeNode*> q;
    int minD = INT_MAX;
    int d = 1;
    bool check = false;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if(node != NULL)
        {
            check = false;
            if(node->left)
            {
                q.push(node->left);
            }

            if(node->right)
            {
                q.push(node->right);
            }

            if(!node->left && !node->right)
            {
                minD = min(minD,d);
                break;
            }
        }
        else if(node == NULL && check == false)
        {
            d++;
            q.push(NULL);
        }    
    }

    return minD;
}

int main()
{
    // TreeNode* root = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(4);
    // root->right->right->right = new TreeNode(5);
    // root->right->right->right->right = new TreeNode(6);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout<<minDepth(root)<<endl;
    
    return 0;
}