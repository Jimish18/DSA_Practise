/*
Question - House Robber III

Link - https://leetcode.com/problems/house-robber-iii/
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

// Alternate level Approach Won't work 'cause of certain greedy cases
// int rob(TreeNode* root) 
// {
//     queue<TreeNode*> q;
//     q.push(root);
//     int n;
//     int level = 1;
//     int sumOdd = 0;
//     int sumEven = 0;

//     while(!q.empty())        
//     {
//         n = q.size();

//         for(int i = 0 ; i < n; i++)
//         {
//             TreeNode* node = q.front();
//             q.pop();

//             if(level%2 == 0)
//             {
//                 sumEven += node->val;
//             }
//             else
//             {
//                 sumOdd += node->val;
//             }

//             if(node->left) q.push(node->left);
//             if(node->right) q.push(node->right);
//         }
//         level++;
//     }

//     return max(sumEven,sumOdd);
// }


// Inclusion - exclusion concept
pair<int,int> tryRob(TreeNode* root)
{
    if(!root)
    {
        return {0,0};
    }

    pair<int,int> left = tryRob(root->left);
    pair<int,int> right = tryRob(root->right);

    pair<int,int> ans;

    ans.first = left.second + right.second + root->val;
    ans.second = max(left.first,left.second) + max(right.first,right.second);

    return ans;
}

int rob(TreeNode* root)
{
    pair<int,int> ans = tryRob(root);

    return max(ans.first,ans.second);
}

int main()
{
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout<<rob(root)<<endl;
    return 0;
}