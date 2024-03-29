/*
Link - https://leetcode.com/problems/construct-string-from-binary-tree/
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

string tree2str(TreeNode* root) 
{
    string ans = to_string(root->val);
    if (root->left) //left side check
        ans += "(" + tree2str(root->left) + ")";
    if (root->right) { //right side check
        if (!root->left) ans += "()"; //left side not present, but right side present
        ans += "(" + tree2str(root->right) + ")"; 
    }
    return ans;
}