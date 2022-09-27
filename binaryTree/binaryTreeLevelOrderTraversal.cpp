/*
Question - Binary Tree Level Order Traversal

Link - https://leetcode.com/problems/binary-tree-level-order-traversal/
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

vector<vector<int>> levelOrder(TreeNode* root) 
{
    if(!root)
    {
        return {};
    }
    vector<vector<int>> result;
    vector<int> temp;
    queue<TreeNode*> q;

    q.push(root);
    q.push(NULL);
    bool check = false;
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if(node != NULL)
        {
            check = false;
            temp.push_back(node->val);
            if(node->left)
            {  
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(node==NULL && check == false)
        {
            result.push_back(temp);
            temp.clear();
            check = true;
            q.push(NULL);
        }        
        
    }    
    // result.push_back(temp);
    // temp.clear();
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    // TreeNode *p1 = new TreeNode(2);
    // TreeNode *p2 = new TreeNode(3);
    // root->left = p1;
    // root->right = p2;

    // TreeNode *p11 = new TreeNode(4);
    // TreeNode *p12 = new TreeNode(5);
    // p1->left = p11;
    // p1->right = p12;

    // TreeNode *p21 = new TreeNode(6);
    // TreeNode *p22 = new TreeNode(7);
    // p2->left = p21;
    // p2->right = p22;

    vector<vector<int>> levelOrderTraversal = levelOrder(root);

    // cout<<levelOrderTraversal.size();

    for(int i = 0 ; i < levelOrderTraversal.size(); i++)
    {
        for(int j = 0 ; j < levelOrderTraversal[i].size(); j++)
        {
            cout<<levelOrderTraversal[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}