#include <bits/stdc++.h>
using namespace std;

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversalVector(TreeNode* root,vector<int> &result)
{
    if(!root)
    {
        return;
    }

    inorderTraversalVector(root->left,result);
    result.push_back(root->val);
    inorderTraversalVector(root->right,result);
}

vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> result;
    
    inorderTraversalVector(root,result);

    return result;
}


int main()
{    
    return 0;
}