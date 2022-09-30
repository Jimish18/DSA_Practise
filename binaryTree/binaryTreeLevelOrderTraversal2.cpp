/*
Question - Binary Tree Level Order Traversal II

Link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    vector<vector<int>> result;

    if(!root)
    {
        return result;
    }      

    queue<TreeNode*> q;
    q.push(root);
    vector<int> temp;
    int n;

    while(!q.empty())
    {
        n = q.size();

        for(int i = 0; i < n; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            temp.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        result.insert(result.begin(),temp);
        temp.clear();
    }

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> levelOrder2 = levelOrderBottom(root);
    
    for(int i = 0 ; i < levelOrder2.size(); i++)
    {
        for(int j = 0 ; j < levelOrder2[i].size(); j++)
        {
            cout<<levelOrder2[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}