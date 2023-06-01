/*
Question - Flood Fill

Link - https://leetcode.com/problems/flood-fill/
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> dc = {0,0,1,-1};
vector<int> dr = {1,-1,0,0};

void dfs(vector<vector<int>>& image,int i,int j,int color,int prev,int n,int m,vector<vector<bool>> &visited)
{
    if(i >= 0 && i < n && j >= 0 && j < m && image[i][j] == prev && !visited[i][j])
    {
        image[i][j] = color;
        visited[i][j] = true;

        for(int k = 0 ; k < 4; k++)
        {
            int newX = i + dr[k];
            int newY = j + dc[k];

            dfs(image,newX,newY,color,prev,n,m,visited);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    int n = image.size();
    int m = image[0].size();

    vector<vector<bool>> visited(n , vector<bool> (m,false));

    dfs(image,sr,sc,color,image[sr][sc],n,m,visited);

    return image;
}

int main()
{
    return 0;
}