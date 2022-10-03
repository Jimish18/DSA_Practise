/*
Question - Flatten Binary  Tree to Linked List

Link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

// O(n) space Complexity
// void dfs(TreeNode* root,vector<TreeNode*> &nodes)
// {
//     if(!root)
//     {
//         return;
//     }
//     dfs(root->left,nodes);
//     nodes.push_back(root);
//     dfs(root->right,nodes);
// }

// void flatten(TreeNode* root) 
// {
//     vector<TreeNode*> nodes;
//     dfs(root->left,nodes);
//     dfs(root->right,nodes);

//     int i = 0;

//     TreeNode* temp = root;
//     while(i < nodes.size())
//     {
//         temp->left = NULL;
//         temp->right = nodes[i];
//         temp = temp->right;
//         i++;
//     }
// }



// O(1) Space Complexity
void flatten(TreeNode* root)
{
    if(!root || (!root->left && !root->right))
    {
        return;
    }

    if(root->left)
    {
        flatten(root->left);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        TreeNode* t = root->right;

        while(t->right)
        {
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);

}

void printFlattenTree(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    cout<<root->val<<" ";
    printFlattenTree(root->right);
}



int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    flatten(root);
    printFlattenTree(root);

    
    return 0;
}