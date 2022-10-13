/*
Question - Complete Binary Tree Inserter

Link - https://leetcode.com/problems/complete-binary-tree-inserter/
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

// brute Force Approach
// class CBTInserter {
//     public:
//     TreeNode* rootTemp;
//     CBTInserter(TreeNode* root) 
//     {
//         rootTemp = root;
//     }
    
//     int insert(int val) 
//     {
//         queue<TreeNode*> q;
//         q.push(rootTemp);
//         int n;

//         while(!q.empty())
//         {
//             n = q.size();
//             for(int i = 0 ; i < n; i++)
//             {
//                 TreeNode* node = q.front();
//                 q.pop();

//                 if(node->left)
//                 {
//                     q.push(node->left);
//                 }
//                 else
//                 {
//                     node->left = new TreeNode(val);
//                     return node->val;
//                 }

//                 if(node->right)
//                 {
//                     q.push(node->right);
//                 }
//                 else
//                 {
//                     node->right = new TreeNode(val);
//                     return node->val;
//                 }
//             }
//         }  
//     }
    
//     TreeNode* get_root() 
//     {
//         return rootTemp;    
//     }
// };

class CBTInserter 
{
    public:
    vector<TreeNode*> v;
    CBTInserter(TreeNode* root) 
    {
        v.push_back(root);
        for(int i = 0 ; i < v.size(); i++)
        {
            if(v[i]->left) v.push_back(v[i]->left);
            if(v[i]->right) v.push_back(v[i]->right);
        }    
    }
    
    int insert(int val) 
    {
        TreeNode* node = new TreeNode(val);
        int n = v.size();
        v.push_back(node);

        if(n%2)
        {
            v[(n-1)/2]->left = node;
        }    
        else
        {
            v[(n-1)/2]->right = node;
        }

        return v[(n-1)/2]->val;
    }
    
    TreeNode* get_root() 
    {
        return v[0];
    }
};


int main()
{
    return 0;
}