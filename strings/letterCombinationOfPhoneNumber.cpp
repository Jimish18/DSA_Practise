/*
Question - Letter Combination of a Phone Number 

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits) 
{
    vector<string> temp;

    if(digits.length() == 0)
    {
        return temp;
    }    

    unordered_map<char,string> umap;
    umap['2'] = "abc";
    umap['3'] = "def";    
    umap['4'] = "ghi";
    umap['5'] = "jkl";
    umap['6'] = "mno";
    umap['7'] = "pqrs";
    umap['8'] = "tuv";
    umap['9'] = "wxyz";

    int i;

    for( i = 0 ; i < umap[digits[0]].length(); i++)
    {
        string tempString = "";
        tempString += umap[digits[0]][i];
        temp.push_back(tempString);
    }

    i=1;
    
    while(i <= digits.length()-1)
    {
        vector<string> temp2 = temp;
        temp.clear();

        for(int j = 0 ; j < temp2.size(); j++)
        {
            for(int k = 0; k < umap[digits[i]].length(); k++)
            {
                string s = temp2[j];
                s += umap[digits[i]][k];
                temp.push_back(s);
            }
        }

        i++;
    }

    return temp;


}

int main()
{
    string s = "2";
    for(int i = 0; i < letterCombinations(s).size(); i++)
    {
        cout<<letterCombinations(s)[i]<<" ";
    }
    cout<<endl;
    return 0;
}