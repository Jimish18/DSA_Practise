/*
Question - Maximum Binary Tree

Link - https://leetcode.com/problems/maximum-binary-tree/
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

// more Time Complexity
// int maxSearch(vector<int> &nums,int start,int end)
// {
//     int maxNum = INT_MIN;

//     for(int i = start; i <= end; i++)
//     {
//         maxNum = max(maxNum,nums[i]);
//     }

//     return maxNum;
// }

// int search(vector<int> &nums,int start,int end,int maxNum)
// {
//     for(int i = start; i <= end ; i++)
//     {
//         if(nums[i] == maxNum)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// TreeNode* build(vector<int> &nums,int start,int end)
// {
//     if(start > end)
//     {
//         return NULL;
//     }

//     int maxNumber = maxSearch(nums,start,end);
//     int pos = search(nums,start,end,maxNumber);

//     TreeNode* root = new TreeNode(maxNumber);
//     if(start == end)
//     {
//         return root;
//     }

//     root->left = build(nums,start,pos-1);
//     root->right = build(nums,pos+1,end);

//     return root;
// }

// TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
// {
//     int end = nums.size()-1;
//     return build(nums,0,end);
// }


// Less Time Complexity
TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
    vector<TreeNode*> st;

    for(int i = 0; i < nums.size(); i++)
    {
        TreeNode* cur = new TreeNode(nums[i]);

        while(!st.empty() && st.back()->val < nums[i])
        {
            cur->left = st.back();
            st.pop_back();
        }
        if(!st.empty())
        {
            st.back()->right = cur;
        }
        st.push_back(cur);
    }

    return st.front();
}

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
    vector<int> nums = {3,2,1};
    // {3,2,1,6,0,5}
    inorderTraversal(constructMaximumBinaryTree(nums));
    return 0;
}