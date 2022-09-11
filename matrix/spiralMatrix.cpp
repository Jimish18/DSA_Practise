#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> result;
    int rowStart = 0;
    int rowEnd = matrix.size()-1;
    int columnStart = 0;
    int columnEnd = matrix[0].size()-1;

    while(rowStart <= rowEnd && columnStart <= columnEnd)
    {
        // for row start
        for(int col = columnStart ; col <= columnEnd; col++)
        {
            result.push_back(matrix[rowStart][col]);
        }
        if(++rowStart > rowEnd)
        {
            break;
        }

        // for column end
        for(int row = rowStart; row <= rowEnd ; row++)
        {
            result.push_back(matrix[row][columnEnd]);
        }
        if(--columnEnd < columnStart)
        {
            break;
        }

        // for row end
        for(int col = columnEnd ; col >= columnStart; col--)
        {
            result.push_back(matrix[rowEnd][col]);
        }
        if(--rowEnd < rowStart)
        {
            break;
        }

        // for column start 
        for(int row = rowEnd; row >= rowStart ; row--)
        {
            result.push_back(matrix[row][columnStart]);
        }
        if(columnStart++ > columnEnd)
        {
            break;
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix ;

    int row;
    cin>>row;
    int column;
    cin>>column;

    for(int i = 0 ; i < row ;i++)
    {
        vector<int> temp;
        for(int j = 0 ; j < column; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }

        matrix.push_back(temp);
    }

    vector<int> v = spiralOrder(matrix);

    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}