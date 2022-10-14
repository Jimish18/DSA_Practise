/*
Question - Find Largest value in each tree Row

Link -
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

vector<int> largestValues(TreeNode* root) 
{
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    int n;
    
    while(!q.empty())
    {
        n = q.size();
        long long maximum = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->val > maximum)
            {
                maximum = node->val;
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(maximum);
    }

    return result;        
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    // root->left->left = new TreeNode(5);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(9);

    vector<int> v = largestValues(root);

    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}