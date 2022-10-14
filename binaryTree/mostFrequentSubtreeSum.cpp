/*
Question - Most Frequent Subtree Sum

Link - https://leetcode.com/problems/most-frequent-subtree-sum/
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

int subTreeSum(TreeNode* root,unordered_map<int,int> &umap)
{
    if(!root)
    {
        return 0;
    }

    int left = subTreeSum(root->left,umap);
    int right = subTreeSum(root->right,umap);

    int sum = root->val + left + right;    

    umap[sum]++;

    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) 
{
    unordered_map<int,int> umap;  
    vector<int> result; 
    int maxi = INT_MIN;

    int sum = subTreeSum(root,umap);

    for(auto x : umap)
    {
        maxi = max(maxi,x.second);
    } 

    for(auto x : umap)
    {
        if(x.second == maxi)
        {
            result.push_back(x.first);
        }
    }

    return result;
}


int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);

    vector<int> v = findFrequentTreeSum(root);

    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}