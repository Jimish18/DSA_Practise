/*
Question - All Nodes Distance K in Binary Tree

Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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

// void subTreeNode(TreeNode* root,int k, vector<int> &result)
// {
//     if(!root || k < 0)
//     {
//         return ;
//     }

//     if(k == 0)
//     {
//         result.push_back(root->val);
//         return;
//     }

//     subTreeNode(root->left,k-1,result);
//     subTreeNode(root->right,k-1,result);
// }

// int distanceKnode(TreeNode* root,TreeNode* target,int k,vector<int> &result) 
// {
//     if(!root)
//     {
//         return -1;
//     }

//     if(root == target)
//     {
//         subTreeNode(root,k,result);
//         return 0;
//     }

//     int dl = distanceKnode(root->left,target,k,result);

//     if(dl != -1)
//     {
//         if(dl+1 == k)
//         {
//             result.push_back(root->val);
//         }
//         else
//         {
//             subTreeNode(root->right,k-dl-2,result);
//         }

//         return 1+dl;
//     }

//     int dr = distanceKnode(root->right,target,k,result);

//     if(dr != -1)
//     {
//         if(dr+1 == k)
//         {
//             result.push_back(root->val);
//         }
//         else
//         {
//             subTreeNode(root->left,k-dr-2,result);
//         }

//         return 1+dr;
//     }
 
//     return -1;
// }

// vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
// {
//     vector<int> result;

//     int k = distanceKnode(root,target,k,result);

//     return result;

// }

void parentPath(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentMap)
{
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        if(temp->left)
        {
            q.push(temp->left);
            parentMap[temp->left] = temp;
        }

        if(temp->right)
        {
            q.push(temp->right);
            parentMap[temp->right] = temp;
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    vector<int> result;

    if(!root) return result;

    unordered_map<TreeNode*,TreeNode*> parentMap;
    parentPath(root,parentMap);

    queue<TreeNode*> q;
    q.push(target);
    unordered_map<TreeNode*,bool> visitedMap;
    visitedMap[target] = true;
    int curDis = 0;

    while(!q.empty())
    {
        int n = q.size();

        if(curDis++ == k) break;

        for(int i = 0 ; i < n; i++)
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left && !visitedMap[temp->left])
            {
                q.push(temp->left);
                visitedMap[temp->left] = true;
            }

            if(temp->right && !visitedMap[temp->right])
            {
                q.push(temp->right);
                visitedMap[temp->right] = true;
            }

            if(parentMap[temp] && !visitedMap[parentMap[temp]])
            {
                q.push(parentMap[temp]);
                visitedMap[parentMap[temp]] = true;
            }
        }
    }

    while(!q.empty())
    {
        result.push_back(q.front()->val);
        q.pop();
    }

    return result;

}




int main()
{
    return 0;
}