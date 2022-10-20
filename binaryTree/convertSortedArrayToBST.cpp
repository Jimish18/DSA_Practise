/*
Question - Covert Sorted Array To BST

Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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

TreeNode* buildBST(vector<int> &nums,int start,int end)
{
    if(start > end)
    {
        return NULL;
    }

    int mid = (start + end)/2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = buildBST(nums,start,mid-1);

    root->right = buildBST(nums,mid+1,end);
    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) 
{   
     
    TreeNode* root = buildBST(nums,0,nums.size()-1);

    return root;
}

int main()
{
    return 0;
}