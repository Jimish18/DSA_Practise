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
    vector<char> v(m,'.');
    vector<vector<char>> result(n,v);


    if(m > 1)
    {
        for(int i = 0 ; i < n; i++)
        {
            j = m-1;
            k = m-1;
            while(j >= 0)
            {
                while(box[i][j] == '.')
                {
                    j--;                    
                }

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

    // int newRow = box[0].size();
    // int newCol = box.size();

    // for(int i = 0 ; i < newRow; i++)
    // {
    //     for(int l = 0 ; l < newCol ; l++)
    //     {
    //         result[i][l] = box[l][i];
    //     }
    // }

    // for(int i = 0 ; i < m/2; i++)
    // {
    //     for(int l = 0; l < n; l++)
    //     {
    //         char temp = box[l][i];
    //         box[l][i] = box[i][l];
    //         box[i][l] = temp;
    //     }
    // }

    return box;       
}

int main()
{
    vector<vector<char>> v = {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};
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