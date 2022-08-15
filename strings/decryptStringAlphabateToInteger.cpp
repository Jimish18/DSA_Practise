/*
Question - Decrypt String from Alphabet to Integer Mapping

You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"
 

Constraints:

1 <= s.length <= 1000
s consists of digits and the '#' letter.
s will be a valid string such that mapping is always possible.
*/

#include <bits/stdc++.h>
using namespace std;

string freqAlphabets(string s) 
{
    string result = "";
    
    for(int i = s.length()-1 ; i >= 0; i--)
    {        
        if(s[i] == '#')
        {
            int n1 = (s[i-2]) - '0';
            int n2 = (s[i-1]) - '0';
            int number = (n1*10)+n2;

            result.insert(result.begin(),(char)(number+96));
            i--;i--;

        }
        else
        {
            int number = (s[i])- '0';
            result.insert(result.begin(),(char)(number+96));
        }
    }    

    return result;
}

int main()
{
    string s = "10#11#12";
    
    cout<<freqAlphabets(s)<<endl;
    return 0;
}