/*
Question - Smallest String Starting From Leaf

Link - https://leetcode.com/problems/smallest-string-starting-from-leaf/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string s = "~";

void dfs(TreeNode* root,string check)
{
    if(!root)
    {
        return;
    }

    if(!root->left && !root->right)
    {
        s = min(s,(char)((root->val) + 'a') + check);
    }    

    dfs(root->left,(char)((root->val) + 'a') + check);
    dfs(root->right,(char)((root->val) + 'a') + check);
}

string smallestFromLeaf(TreeNode* root) 
{
    string check = "";

    dfs(root,check);

    return s;
}

int main()
{
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    // TreeNode* root = new TreeNode(25);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(2);

    cout<<smallestFromLeaf(root)<<endl;
    // cout<<("~" > "")<<endl;
    return 0;
}