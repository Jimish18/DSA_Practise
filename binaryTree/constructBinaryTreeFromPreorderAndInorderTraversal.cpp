/*
Question - Construct Binary Tree From Inorder And Pre Order Traversal

Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

    
TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) 
{
    if (left > right) 
    {
        return NULL;
    }
    int pivot = left;  // find the root from inorder
    while(inorder[pivot] != preorder[rootIdx]) 
    {
        pivot++;
    }
    
    rootIdx++;
    TreeNode* newNode = new TreeNode(inorder[pivot]);
    newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
    newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
    return newNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    int rootIdx = 0;
    return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
}

// (Overflow accessing) 
// int search(vector<int> inorder,int start,int end,int target)
// {
//     for(int i = start ; i <= end; i++)
//     {
//         if(inorder[i] == target)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// TreeNode* buildTreeHere(vector<int> preorder, vector<int> inorder,int start,int end)
// {
//     static int idx = 0;
//     if(start > end)
//     {
//         return NULL;
//     }
//     int curr = preorder[idx];
//     idx++;
//     TreeNode* root = new TreeNode(curr);
//     if(start == end)
//     {
//         return root;
//     }
//     int pos = search(inorder,start,end,curr);
//     root->left = buildTreeHere(preorder,inorder,start,pos-1);
//     root->right = buildTreeHere(preorder,inorder,pos+1,end);

//     return root;
// }

// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
// {
//     int start = 0;
//     int end = inorder.size()-1;
//     return buildTreeHere(preorder,inorder,start,end);
// }

void inorderTraversal(TreeNode* root)
{
    if(!root)
    {
        return ;
    }

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> preOrder = {-1}; //{3,9,20,15,7}
    vector<int> inOrder = {-1}; //{9,3,15,20,7}

    inorderTraversal(buildTree(preOrder,inOrder));
    return 0;
}