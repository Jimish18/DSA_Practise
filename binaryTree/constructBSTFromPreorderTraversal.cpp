/*
Question - Construct BST from Preorder Traversal

Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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

TreeNode* buildBST(vector<int> &inorder,vector<int> &preorder,int &index,int left,int right)
{
    if(left > right)
    {
        return NULL;
    }

    int pivot = preorder[index];

    int i = left;

    while(inorder[i] != pivot)
    {
        i++;
    }

    TreeNode* root = new TreeNode(inorder[i]);
    index++;

    root->left = buildBST(inorder,preorder,index,left,i-1);
    root->right = buildBST(inorder,preorder,index,i+1,right);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) 
{
    vector<int> inorder = preorder;

    sort(inorder.begin(),inorder.end());
    int index = 0;
    int n = preorder.size();

    return buildBST(inorder,preorder,index,0,n-1);

}

int main()
{


    return 0;
}