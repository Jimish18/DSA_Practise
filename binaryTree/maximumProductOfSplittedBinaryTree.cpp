/*
Question - Maximum Product of Splitted Binary Tree

link - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

ll maxP = 0;
ll totalSum = 0;

ll sumOfTree(TreeNode* root)
{
    if(!root) return 0;

    return root->val + sumOfTree(root->left) + sumOfTree(root->right);
}

int dfs(TreeNode* root)
{
    if(!root) return 0;

    ll sum = dfs(root->left) + dfs(root->right) + root->val;
    maxP = max(maxP,sum*(totalSum-sum));

    return sum;
}

int maxProduct(TreeNode* root) 
{
    int m = 1e9+7;
    totalSum = sumOfTree(root);  
    dfs(root);
    int result = (maxP)%(m);

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // cout<<sumOfTree(root)<<endl;
    cout<<maxProduct(root)<<endl;
    return 0;
}