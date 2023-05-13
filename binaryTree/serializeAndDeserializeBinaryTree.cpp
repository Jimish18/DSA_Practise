/*
Question - Serialize And Deserialize

Link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        
        string s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(node->val)+',');
            }
            if(node!=NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }     
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root=new TreeNode(stoi(str));
            queue<TreeNode*>q;
            q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
              getline(s, str, ',');
            if(str=="#")
            {
                node->left=NULL;
            }
            else
            {
                TreeNode* l=new TreeNode(stoi(str));
                node->left=l;
                q.push(l);
            }
            
             getline(s, str, ',');
            if(str=="#")
            {
                node->right=NULL;
            }
            else
            {
                TreeNode* r=new TreeNode(stoi(str));
                node->right=r;
                q.push(r);
            }
            
        }
        return root;
        
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string temp = serialize(root);
    TreeNode* root2 = deserialize(temp);
    inorder(root2);

    for(auto x : inorderTraversal)
    {
        cout<<x<<" ";
    }
    return 0;
}