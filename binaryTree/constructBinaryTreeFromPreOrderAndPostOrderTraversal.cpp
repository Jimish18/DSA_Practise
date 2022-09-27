/*
Question - Construct Binary Tree from Preorder and Postorder Traversal

Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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

int preIndex = 0, posIndex = 0;
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
{
    TreeNode* root = new TreeNode(pre[preIndex++]);
    if (root->val != post[posIndex])
    {
        root->left = constructFromPrePost(pre, post);
    }
        
    if (root->val != post[posIndex])
    {
        root->right = constructFromPrePost(pre, post);
    }            
    posIndex++;
    return root;
}
// (Access OverFlow)
// TreeNode* build(vector<int> &preorder,vector<int> postorder,int &idx,int start,int end)
// {
//     if(start > end)
//     {
//         return NULL;
//     }
//     TreeNode* root = new TreeNode(preorder[idx]);
//     idx++;
//     int pivot = end;
//     while(postorder[pivot] != preorder[idx])
//     {
//         pivot--;
//     }
    
//     if(start == end)
//     {
//         return root;
//     }

//     root->left = build(preorder,postorder,idx,start,pivot);
//     root->right = build(preorder,postorder,idx,pivot+1,end-1);

//     return root;
// }

// TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
// {
//     int end = preorder.size();
//     int idx = 0;
//     return build(preorder,postorder,idx,0,end-1);
// }

void inorderTraversal(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}


int main()
{
    vector<int> preorder = {1}; //1,2,4,5,3,6,7
    vector<int> postorder = {1}; //4,5,2,6,7,3,1

    inorderTraversal(constructFromPrePost(preorder,postorder));
    return 0;
}