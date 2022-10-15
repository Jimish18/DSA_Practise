/*
Question - find Duplicate SubTrees

Link - https://leetcode.com/problems/find-duplicate-subtrees/
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

unordered_map<string,int> umap;
vector<TreeNode*> result;
string preorder(TreeNode* root)
{
    if(!root)
    {
        return "$";
    }

    string left = preorder(root->left);
    string right = preorder(root->right);
    string s = to_string(root->val) + "$" +left + "$" +right;

    if(umap[s] == 1)
    {
        result.push_back(root);
    }
    
    umap[s]++;

    return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
    if(!root)
    {
        return result;
    }

    preorder(root);

    return result;
}

int main()
{
    return 0;
}