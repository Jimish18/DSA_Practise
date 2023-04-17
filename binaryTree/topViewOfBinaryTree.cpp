/*
Question - Top View Of Binary Tree

Link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node *root)
{
    vector<int> result;

    if(!root) return result;
    map<int,int> umap;
    queue<pair<Node*,int>> q;

    q.push({root,0});
    
    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();

        if(umap.find(temp.second) == umap.end()) umap[temp.second] = temp.first->data;

        if(temp.first->left) q.push({temp.first->left,temp.second-1});

        if(temp.first->right) q.push({temp.first->right,temp.second+1});
    }

    for(auto x : umap)
    {
        result.push_back(x.second);
    }

    return result;
}



int main()
{
    return 0;
}