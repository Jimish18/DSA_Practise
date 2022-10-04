/*
Question - Populating Next Right Pointer In Each Node

Link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) 
{
    if(!root)
    {
        return NULL;
    }
    
    queue<Node* > q;

    q.push(root); 
    int n;

    while(!q.empty())
    {
        n = q.size();

        for(int i = 0 ; i < n; i++)
        {
            Node* node = q.front();;
            q.pop();

            
            if(i != n-1)
            {
                node->next = q.front();
            }

            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return root;

}

vector<int> printVector(Node* root)
{
    vector<int> result;
    queue<Node*> q;
    int n;
    q.push(root);

    while(!q.empty())
    {
        n = q.size();

        for(int i = 0 ; i < n ; i++)
        {
            Node* node = q.front();
            q.pop();

            result.push_back(node->val);

            if(node->next)
            {
                result.push_back(node->next->val);
            }
            else
            {
                result.push_back(-1);
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return result;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> nextOrderTraversal = printVector(connect(root));

    for(int i = 0; i < nextOrderTraversal.size(); i++)
    {
        cout<<nextOrderTraversal[i]<<" ";
    }
    return 0;
}