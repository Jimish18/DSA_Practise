/*
Quetion - Unique Paths

Link - https://leetcode.com/problems/unique-paths/
*/

#include <bits/stdc++.h>
using namespace std;



int uniquePaths(int m, int n) 
{
    if(m == 1 || n == 1)
        return 1;
    m--;
    n--;
    if(m < n) {              // Swap, so that m is the bigger number
        m = m + n;
        n = m - n;
        m = m - n;
    }
    long res = 1;
    int j = 1;
    for(int i = m+1; i <= m+n; i++, j++){       // Instead of taking factorial, keep on multiply & divide
        res *= i;
        res /= j;
    }
        
    return (int)res;          
}

// Recursive Way - TLE
// int countUniquePaths(int m,int n,int i,int j)
// {
//     if(i == m-1 && j == n-1)
//     {
//         return 1;
//     }

//     if(i >= m || j >= n)
//     {
//         return 0;
//     }

//     return countUniquePaths(m,n,i+1,j) + countUniquePaths(m,n,i,j+1);
// }

// int uniquePaths(int m, int n) 
// {
//     return countUniquePaths(m,n,0,0);          
// }

int main()
{
    cout<<uniquePaths(3,2)<<endl;
    return 0;
}