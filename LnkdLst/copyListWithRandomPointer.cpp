/*
Question - Copy List With Random Pointer

Link - https://leetcode.com/problems/copy-list-with-random-pointer/
*/

#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:    
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void insertAtTail(Node* &head,int val)
{
    Node* temp = head;

    if(!head)
    {
        head = new Node(val);
        return ;
    }

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = new Node(val);
}

// O(N^2) Solution
Node* copyRandomList(Node* head) 
{
    Node* temp = head;
    Node* newHead = NULL;

    while(temp)
    {
        insertAtTail(newHead,temp->val);
        temp = temp->next;
    }

    temp = head;
    unordered_map<int,int> umap;
    int index = 0;

    while(temp)
    {
        int tempIndex = 0;
        Node* randomNode = temp->random;
        Node* tempRandom = head;

        if(!randomNode)
        {
            umap[index] = -1;
            temp = temp->next;
            index++;
            continue;
        }

        while(tempRandom != randomNode)
        {
            tempRandom = tempRandom->next;
            tempIndex++;
        }

        umap[index] = tempIndex;
        index++;
        temp = temp->next;
    }

    temp = newHead;
    index = 0;

    while(temp)
    {
        int tempIndex = umap[index];
        Node* tempRandom = newHead;

        if(tempIndex == -1)
        {
            while(tempRandom) tempRandom = tempRandom->next;
            temp->random = tempRandom;
        }
        else
        {
            while(tempIndex--)
            {
                tempRandom = tempRandom->next;
            }

            temp->random = tempRandom;
        }

        temp = temp->next;
        index++;
    }

    return newHead;

}

// O(N) solution
Node* copyRandomList(Node* head) 
{
    if(!head) return head;

    unordered_map<Node*,Node*> umap;
    Node* temp = head;

    while(temp)
    {
        if(!umap[temp]) umap[temp] = new Node(temp->val);
        temp = temp->next;
    }

    temp = head;

    while(temp)
    {
        umap[temp]->next = temp->next ? umap[temp->next] : NULL;
        umap[temp]->random = temp->random ? umap[temp->random] : NULL;
        temp = temp->next;
    }

    return umap[head];
}



int main()
{
    return 0;
}