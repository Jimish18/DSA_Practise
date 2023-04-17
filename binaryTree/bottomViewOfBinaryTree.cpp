/*
Question - Bottom View Of Binary Tree

Link - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector <int> bottomView(Node *root) 
{
    map<int,vector<int>> umap;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();

        umap[temp.second].push_back(temp.first->data);

        if(temp.first->left) q.push({temp.first->left,temp.second-1});
        if(temp.first->right) q.push({temp.first->right,temp.second+1});
    }

    vector<int> result;

    for(auto x : umap)
    {
        result.push_back(x.second[x.second.size()-1]);
    }

    return result;
}

int main()
{
    return 0;
}