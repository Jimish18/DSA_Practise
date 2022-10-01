/*
Question - N-ary Tree Level Order Traversal

Link - https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) 
{
    vector<vector<int>> result;
    vector<int> temp;
    int n;

    queue<Node*> q;

    q.push(root);

    while(!q.empty())     
    {
        n = q.size();
        for(int i = 0 ; i < n ; i++)
        {
            Node* node = q.front();
            q.pop();

            temp.push_back(node->val);

            for(auto child : node->children)
            {
                q.push(child);
            }
        }
        result.push_back(temp);
        temp.clear();
    }  

    return result;
}

int maain()
{
    Node* p2 = new Node(2);
    Node* p3 = new Node(4);
    Node* p11 = new Node(5);
    Node* p12 = new Node(6);
    Node* p1 = new Node(3,{p11,p12});
    Node* root = new Node(1,{p1,p2,p3});

    vector<vector<int>> v = levelOrder(root);

    // for(int i = 0 ; i < v.size() ; i++)
    // {
    //     for(int j = 0 ;  j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}