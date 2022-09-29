/*
Question - binary Tree Right Side view

Link - https://leetcode.com/problems/binary-tree-right-side-view/
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

vector<int> rightSideView(TreeNode* root) 
{
    vector<int> result;

    queue<TreeNode*> q;
    q.push(root);
    int n;

    while(!q.empty())
    {
        n = q.size();
        for(int i = 0; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(i == n-1)
            {
                result.push_back(node->val);
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);


        }
    }

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);

    vector<int> rightView = rightSideView(root);

    for(int i = 0 ; i < rightView.size(); i++)
    {
        cout<<rightView[i]<<" "; 
    }
    cout<<endl;
    return 0;
}