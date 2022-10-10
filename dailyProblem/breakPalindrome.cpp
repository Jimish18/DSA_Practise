/*
Question - break a Palindrome

Link - https://leetcode.com/problems/break-a-palindrome/
*/

#include <bits/stdc++.h>
using namespace std;

string breakPalindrome(string palindrome) 
{
    int n = palindrome.length();
    if(n == 1)
    {
        return "";
    }

    for(int i = 0 ; i < n/2; i++)
    { 

        if(palindrome[i] != 'a')
        {
            palindrome[i] = 'a';
            return palindrome;
        }
    }  

    palindrome[n-1] = 'b';
    return palindrome;
}

int main()
{
    string s = "aba";
    // "abccba"
    cout<<breakPalindrome(s)<<endl;
    return 0;
}