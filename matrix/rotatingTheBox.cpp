/*
Question - Rotating the Box

Link - https://leetcode.com/problems/rotating-the-box/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
{
    int n = box.size();
    int m = box[0].size();
    int j,k;
    vector<char> v(n,'.');
    vector<vector<char>> result(m,v);


    if(m > 1)
    {
        for(int i = 0 ; i < n; i++)
        {
            j = m-1;
            k = m-1;
            while(j >= 0)
            {
                while(j >= 0 && box[i][j] == '.')
                {
                    j--;                    
                }
                
                if(j < 0) break;

                if(box[i][j] == '*')
                {
                    j--;
                    k = j;
                }                
                else if(box[i][j] == '#' && box[i][k] == '.')
                {
                    char temp = box[i][j];
                    box[i][j] = box[i][k];
                    box[i][k] = temp;
                    j--;
                    k--;
                }
                else
                {
                    j--;
                    k--;
                }
            }
        }
    }

    int newRow = box[0].size();
    int newCol = box.size();

    for(int i = 0 ; i < newRow; i++)
    {
        for(int l = 0 ; l < newCol ; l++)
        {
            result[i][l] = box[l][i];
        }
    }

    for(int i = 0 ; i < newCol/2; i++)
    {
        for(int l = 0; l < newRow; l++)
        {
            swap(result[l][i],result[l][newCol-i-1]);
        }
    }

    return result;       
}

int main()
{
    vector<vector<char>> v = {{'#','.','*','.'},{'#','#','*','.'}};
    // {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};
    vector<vector<char>> result = rotateTheBox(v);

    for(int i = 0 ;i < result.size(); i++)
    {
        for(int j = 0 ; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}