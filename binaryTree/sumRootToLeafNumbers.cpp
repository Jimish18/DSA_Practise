/*
Question - Sum Root To Leaf Numbers

Link - https://leetcode.com/problems/sum-root-to-leaf-numbers/
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

int dfs(TreeNode* root,int sum)
{
    if(!root)
    {
        return 0;
    }

    sum = (sum*10)+(root->val);

    if(!root->left && !root->right)
    {
        return sum;
    }

    return dfs(root->left,sum) + dfs(root->right,sum);

}

int sumNumbers(TreeNode* root) 
{
    int sum = 0;
    return dfs(root,sum);
}

int main()
{
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);
    

    cout<<sumNumbers(root)<<endl;
    return 0;
}