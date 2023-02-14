/*
Question - Add Binary

Link - https://leetcode.com/problems/add-binary/
*/

#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) 
{
    int i = a.length()-1;
    int j = b.length() -1;
    string ans;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry)
    {
        if(i >= 0)
        {
            carry += a[i] - '0';
            i--;
        }

        if(j >= 0)
        {
            carry += b[j] -'0';
            j--;
        }

        ans.insert(ans.begin(),(carry%2 + '0'));

        carry = carry/2;
    }

    return ans;

}

int main()
{
    return 0;
}