/*
Question - Deepest Leaves Sum

Link - https://leetcode.com/problems/deepest-leaves-sum/
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

// Less Space Complexity
int deepestLeavesSum(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    int sum = 0,n;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        sum = 0;
        n = q.size();

        for(int i = 0; i < n; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);
        }
    }

    return sum;
}

// More Space Complexity
// int deepestLeavesSum(TreeNode* root) 
// {
//     if(!root)
//     {
//         return 0;
//     }

//     unordered_map<int,int> umap;
//     queue<TreeNode*> q;
//     bool check = false;
//     int d = 1;

//     q.push(root);
//     q.push(NULL);

//     while(!q.empty())
//     {
//         TreeNode* node = q.front();
//         q.pop();

//         if(node != NULL)
//         {
//             check = false;
//             if(!node->left && !node->right)
//             {
//                 umap[d] += node->val;
//             }

//             if(node->left)
//             {
//                 q.push(node->left);
//             }

//             if(node->right)
//             {
//                 q.push(node->right);
//             }
//         }
//         else if(node == NULL && check == false)
//         {
//             check = true;
//             d++;
//             q.push(NULL);
//         }
//     }   

//     int deep = INT_MIN;

//     for(auto i : umap)
//     {
//         deep = max(deep,i.first);
//     }   

//     return umap[deep];
// }

int main()
{
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->left->left = new TreeNode(7);
    // root->right->right = new TreeNode(6);
    // root->right->right->right = new TreeNode(8);

    TreeNode* root = new TreeNode(6);
    TreeNode* p1 = new TreeNode(7);
    TreeNode* p2 = new TreeNode(8);
    TreeNode* p11 = new TreeNode(2);
    TreeNode* p12 = new TreeNode(7);
    TreeNode* p111 = new TreeNode(9);
    TreeNode* p121 = new TreeNode(1);
    TreeNode* p122 = new TreeNode(4);
    TreeNode* p21 = new TreeNode(1);
    TreeNode* p22 = new TreeNode(3);
    TreeNode* p222 = new TreeNode(5);

    root->left = p1;
    root->right = p2;
    p1->left = p11;
    p1->right = p12;
    p11->left = p111;
    p12->left = p121;
    p12->right = p122;
    p2->left = p21;
    p2->right = p22;
    p22->right = p222;

    cout<<deepestLeavesSum(root)<<endl;
    return 0;
}