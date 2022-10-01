/*
Question - path Sum II

Link - https://leetcode.com/problems/path-sum-ii/
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



void calcPathSum(TreeNode* root,vector<vector<int>> &result,vector<int> &path,int targetSum,int curSum)
{
    if(!root)
    {
        return;
    }

    curSum += root->val;

    path.push_back(root->val);

    if(!root->left && !root->right && curSum == targetSum)
    {
        result.push_back(path);
        path.pop_back();
        return;
    }


    calcPathSum(root->left,result,path,targetSum,curSum);    
    calcPathSum(root->right,result,path,targetSum,curSum);    
    path.pop_back();
    
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{   
    vector<vector<int>> result;   
    vector<int> path;

    calcPathSum(root,result,path,targetSum,0);

    return result;     
}

void inOrederTraversal(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    inOrederTraversal(root->left);
    cout<<root->val<<" ";
    inOrederTraversal(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> v = pathSum(root,22);

    for(int i = 0 ;i < v.size(); i++)
    {
        for(int j = 0 ; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    // inOrederTraversal(root);
    return 0;
}