/*
Question - Two Sum IV - Input is a BST

Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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

bool findTarget(TreeNode* root, int k) 
{
    queue<TreeNode*> q;
    q.push(root);
    unordered_set<int> st;
    int n ;

    while(!q.empty())
    {
        n = q.size();
        for(int i = 0 ; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(st.find(k-(node->val)) != st.end())
            {
                return true;
            }
            else
            {
                st.insert(node->val);  
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
    }
    return false;    
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout<<findTarget(root,28)<<endl;
    return 0;
}