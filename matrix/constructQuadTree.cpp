/*
Question - Construct Quad Tree

Link - https://leetcode.com/problems/construct-quad-tree/
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

bool checkSame(vector<vector<int>> &grid,int row,int col,int n)
{
    int first = grid[row][col];

    for(int i = row; i < row + n ; i++)
    {
        for(int j = col; j < col + n ; j++)
        {
            if(grid[i][j] != first) return false;
        }
    }

    return true;
}


Node* dfs(vector<vector<int>>& grid,int i,int j,int n)
{
    if(checkSame(grid,i,j,n))
    {
        return new Node(grid[i][j],true);
    }

    Node* root = new Node(true,false);
    root->topLeft = dfs(grid,i,j,n/2);
    root->topRight = dfs(grid,i,j+n/2,n/2);
    root->bottomLeft = dfs(grid,i+n/2,j,n/2);
    root->bottomRight = dfs(grid,i+n/2,j+n/2,n/2);

    return root;
}

Node* construct(vector<vector<int>>& grid) 
{
    int n = grid.size();     

    return dfs(grid,0,0,n);   
}


int main()
{
    return 0;
}