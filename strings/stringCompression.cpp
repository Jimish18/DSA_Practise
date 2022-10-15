/*
Question - string Compression

Link - https://leetcode.com/problems/string-compression/
*/

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) 
{
    int count = 0;
    int i = 0 , j = 0;
    int n = chars.size();
    string temp = "";


    while(i < n)
    {
        if(chars[i] == chars[j])
        {
            count++;
            i++;            
        }
        else
        {            
            if(count > 1)
            {
                temp += chars[j];
                temp += to_string(count);
            }
            else
            {
                temp += chars[j];
            }
            j = i;
            count = 0;
        }

        if(i == n-1)
        {
            if(count > 1)
            {
                temp += chars[j];
                temp += to_string(count);
            }
            else
            {
                temp += chars[j];
            }
        }
    }

    chars.clear();

    for(int k = 0; k < temp.length(); k++)
    {
        chars.push_back(temp[k]);
    }

    return temp.length();
          
}

int main()
{
    return 0;
}