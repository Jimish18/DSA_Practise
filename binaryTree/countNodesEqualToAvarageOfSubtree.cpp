/*
Question - Count Nodes Equal to Average of Subtree

Link - https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Perfect DFS Approach O(n)
int ans = 0;

pair<int,int> solve(TreeNode* root)
{
    if(!root)
    {
        return {0,0};
    }

    auto left = solve(root->left);
    int leftSum = left.first;
    int leftCount = left.second;

    auto right = solve(root->right);
    int rightSum = right.first;
    int rightCount = right.second;

    int totalSum = leftSum + root->val + rightSum;
    int totalCount = leftCount + 1 + rightCount;

    if(totalSum/totalCount == root->val)
    {
        ans++;
    }

    return {totalSum,totalCount};
}

int averageOfSubtree(TreeNode* root) 
{
    solve(root);
    return ans;
}

// recursive returning avg error
// int avgOfSubTree(TreeNode* root,int &count)
// {
//     int tempCount = 1;
//     int rootValue = root->val;
//     double sum = rootValue;
//     double leftValue = 0,rightValue = 0;

//     if(root->left)
//     {
//         leftValue = avgOfSubTree(root->left,count);
//         tempCount++;
//     }

//     if(root->right)
//     {
//         rightValue = avgOfSubTree(root->right,count);
//         tempCount++;
//     }

//     sum += floor(leftValue + rightValue);
//     int avg = sum/tempCount;

//     if(floor(avg) == rootValue)
//     {
//         count++;
//     }

//     return avg;
// }

// int averageOfSubtree(TreeNode* root) 
// {
//     if(!root)
//     {
//         return 0;
//     }
//     int count = 0;
//     int avg = avgOfSubTree(root,count);

//     return count;
// }

int main()
{
    // Test Case 1
    // TreeNode* root = new TreeNode(4);
    // root->left = new TreeNode(8);
    // root->right = new TreeNode(5);
    // root->left->left = new TreeNode(0);
    // root->left->right = new TreeNode(1);
    // root->right->right = new TreeNode(6);

    // Test Case 2
    // TreeNode* root = new TreeNode(1);

    // Test Case 3
    TreeNode* root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(3);
    root->right->left = NULL;
    root->right->right = new TreeNode(1);
    root->right->right->left = NULL;
    root->right->right->right = new TreeNode(3);

    cout<<averageOfSubtree(root)<<endl;
    return 0;
}