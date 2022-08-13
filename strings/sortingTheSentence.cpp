/*
Question - Sorting the Sentence

A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
Each word consists of lowercase and uppercase English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

*/

#include <bits/stdc++.h>
using namespace std;

string sortSentence(string s) 
{
    vector<string> v;
    string word = "";
    for(int i = 0 ; i < s.length(); i++)
    {        

        if(s[i] == ' ')
        {
            v.push_back(word);
            word = "";
        }
        else if(i == s.length() - 1 )
        {   
            word += s[i];
            v.push_back(word);
        }
        else
        {
            word += s[i];
        }
    }

    vector<string> v2(v.size());

    for(int i = 0 ; i < v.size(); i++)
    {
        int index = (int)(v[i][v[i].size()-1]) - 48;
        v[i].pop_back();
        v2[index-1] = v[i];
    }

    string sentence = "";

    for(int i = 0 ; i < v2.size() ;i++)
    {
        sentence += v2[i];
        sentence += " ";
    }

    sentence.pop_back();

    return sentence;
}

int main()
{
    string s = "is2 sentence4 This1 a3";
    cout<<sortSentence(s)<<endl;
    // cout<<('9' < '0');
    return 0;
}