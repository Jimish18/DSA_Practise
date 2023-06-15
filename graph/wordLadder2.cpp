/*
Question - Word Ladder II

Link - https://leetcode.com/problems/word-ladder-ii/
*/

#include <bits/stdc++.h>
using namespace std;

// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
// {
//     queue<vector<string>> q;
//     q.push({beginWord});
//     unordered_set<string> st(wordList.begin(),wordList.end());
//     vector<string> usedOnLevel;
//     usedOnLevel.push_back(beginWord);
    
//     int level = 0;
//     vector<vector<string>> ans;

//     while(!q.empty())
//     {
//         vector<string> vec = q.front();
//         q.pop();

//         if(vec.size() > level) 
//         {
//             level++;
//             for(auto x : usedOnLevel)
//             {
//                 st.erase(x);
//             }
//             usedOnLevel.clear();
//         }

//         string word = vec.back();

//         if(word == endWord)
//         {
//             if(ans.size() == 0) ans.push_back(vec);
//             else if(ans[0].size() == vec.size()) ans.push_back(vec);
//         }

//         for(int i = 0; i < word.size(); i++)
//         {
//             char original = word[i];

//             for(char j = 'a' ; j <= 'z' ; j++)
//             {
//                 word[i] = j;

//                 if(st.find(word) != st.end())
//                 {
//                     vec.push_back(word);
//                     q.push(vec);
//                     usedOnLevel.push_back(word);
//                     vec.pop_back();
//                 }
//             }

//             word[i] = original;
//         }
//     }    

//     return ans;    
// }

unordered_map<string,int> umap;
vector<vector<string>> ans;
string b;

void dfs(string word,vector<string> &seq)
{
    if(word == b)
    {
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }

    int steps = umap[word];
    int sz = word.size();
    for(int i = 0; i < sz ; i++)
    {
        char original = word[i];

        for(char j = 'a' ; j <= 'z' ; j++)
        {
            word[i] = j;

            if(umap.find(word) != umap.end() && umap[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }

        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<string> q;
    q.push(beginWord);
    b = beginWord;
    umap[beginWord] = 1;
    int sz = beginWord.size();

    st.erase(beginWord);
    while(!q.empty())
    {
        string word = q.front();
        int steps = umap[word];
        q.pop();

        if(word == endWord) break;
        for(int i = 0; i < sz; i++)
        {
            char original = word[i];

            for(char j = 'a' ; j <= 'z'; j++)
            {
                word[i] = j;
                if(st.find(word) != st.end())
                {
                    q.push(word);
                    st.erase(word);
                    umap[word] = steps+1;
                }
            }

            word[i] = original;
        }
    }

    if(umap.find(endWord) != umap.end())
    {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord,seq);
    }

    return ans;

}

int main()
{
    return 0;
}