/*
Question - reverse vowels of a string 

Link - https://leetcode.com/problems/reverse-vowels-of-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }

    return false;
}

string reverseVowels(string s) 
{
    int i = 0;
    int j = s.length()-1;

    while(j >= i)
    {
        if(isVowel(s[i]) && isVowel(s[j]))
        {
            swap(s[i],s[j]);
        }
        else if(isVowel(s[i]))
        {
            j--;
            continue;
        }
        else if(isVowel(s[j]))
        {
            i++;
            continue;
        }

        i++;
        j--;
    }    

    return s;    
}

int main()
{
    string s = "leetcode";
    cout<<reverseVowels(s)<<endl;
    return 0;
}