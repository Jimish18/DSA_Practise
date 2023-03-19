/*
Question - Implement Trie

Link - https://leetcode.com/problems/implement-trie-prefix-tree/
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    vector<Node*> v = vector<Node*>(26,NULL);
    bool isEnd = false;
};

class Trie 
{
    public:

    Node* root;

    Trie() 
    {  
        root = new Node();
    }

    void insert(string word) 
    {
        Node* currNode = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            int chIdx = word[i]-'a';
            if(!currNode->v[chIdx]) currNode->v[chIdx] = new Node();

            currNode = currNode->v[chIdx];
        }

        currNode->isEnd = true;
    }
    
    Node* getPrefixEndNode(string& word) 
    {
        Node* currNode = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            int chIdx = word[i]-'a';
            if(!currNode->v[chIdx]) return NULL;

            currNode = currNode->v[chIdx];
        }

        return currNode;
    }
    
    bool search(string word) 
    {
        Node* preFixNode = getPrefixEndNode(word);
        if(!preFixNode) return false;
        return (preFixNode->isEnd);
    }
    
    bool startsWith(string prefix) 
    {
        Node* preFixNode = getPrefixEndNode(prefix);
        if(!preFixNode) return false;
        return true;
    }
};


int main()
{
    return 0;
}