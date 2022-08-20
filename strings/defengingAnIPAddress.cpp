/*
Question - Defanging An IP Address

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/
#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) 
{
    string replacement = "";

    for(int i = 0 ; i < address.length(); i++)
    {
        if(address[i] == '.')
        {            
            replacement += "[.]";
        }
        else
        {
            replacement += address[i];
        }
    }

    return replacement;
}

int main()
{
    string s = "255.100.50.0";
    // s.erase(1,1);
    // s.insert(1,"[.]");
    cout<<defangIPaddr(s)<<endl;
    // cout<<s<<endl;

    return 0;
}