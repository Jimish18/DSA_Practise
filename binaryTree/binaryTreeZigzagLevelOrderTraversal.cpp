/*
Question - Binary Tree Zigzag Level Order Traversal

Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int>> result;

    if(!root)
    {
        return result;
    }

    queue<TreeNode*> q;
    bool check = false;
    int n;
    vector<int> temp;

    q.push(root);

    while(!q.empty())
    {
        n = q.size();

        for(int i = 0 ; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(check == false)
            {
                temp.push_back(node->val);
            }
            else
            {
                temp.insert(temp.begin(),node->val);
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    
        result.push_back(temp);
        temp.clear();
        check = !check;
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
    vector<vector<int>> zigzagOrder = zigzagLevelOrder(root);
    
    for(int i = 0 ; i < zigzagOrder.size(); i++)
    {
        for(int j = 0 ; j < zigzagOrder[i].size(); j++)
        {
            cout<<zigzagOrder[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}