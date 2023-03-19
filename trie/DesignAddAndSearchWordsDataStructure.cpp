/*
Question - Design Add And Search Words Data Structure

Link - https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    vector<Node*> v = vector<Node*> (26,NULL);
    bool isEnd = false;
};

class WordDictionary 
{
    public:
    Node* root ;


    WordDictionary() 
    {
        root = new Node();    
    }
    
    void addWord(string word) 
    {
        Node* curNode = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            int chIdx = word[i] - 'a';
            if(!curNode->v[chIdx]) curNode->v[chIdx] = new Node();

            curNode = curNode->v[chIdx];
        }    

        curNode->isEnd = true;
    }

    bool searchWord(string word,Node* node)
    {
        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if(ch == '.')
            {
                for(auto x : node->v)
                {
                    if(x && searchWord(word.substr(i+1),x)) return true;
                }
                return false;
            }
            else
            {
                int chIdx = ch-'a';
                if(!node->v[chIdx]) return false;
                node = node->v[chIdx];
            }

            return node->isEnd;
        }
    }
    
    bool search(string word) 
    {
        return searchWord(word,root);
    }
};


int main()
{
    return 0;
}