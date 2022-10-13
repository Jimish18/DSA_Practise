/*
Question - Maximum Width Of Binary Tree

Link - https://leetcode.com/problems/maximum-width-of-binary-tree/
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

int widthOfBinaryTree(TreeNode* root) 
{
    int ans = INT_MIN;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    int leftMost,rightMost;
    int n;

    while(!q.empty())
    {
        n = q.size();
        int mmin = q.front().second;

        for(int i = 0 ; i < n; i++)
        {       
            long long curID = q.front().second - mmin;     
            TreeNode* node = q.front().first;
            q.pop();

            if(i == 0) leftMost = curID;
            if(i == n-1) rightMost = curID;

            if(node->left) q.push({node->left,(curID*2 + 1)});
            if(node->right) q.push({node->right,(curID*2 + 2)});
        }

        ans = max(ans,(rightMost-leftMost+1));

    }    

    return ans;    
}




int main()
{
    return 0;
}