/*
Question -  Flatten a Multilevel Doubly Linked List

Link - https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


Node *flattenList(Node* &head)
{
    Node* temp = head;
    Node* last;

    while(temp)
    {
        if(temp->child)
        {
            Node* nextLink = temp->next;
            last = flattenList(temp->child);            
            last->next = nextLink;
            if(nextLink) nextLink->prev = last;
            temp->next = temp->child;
            temp->next->prev = temp;
            temp->child = NULL;
        }
        if(!temp->next) return temp;
        temp = temp->next;       
    }

    return NULL;
}

Node* flatten(Node* head) 
{
    Node* temp = flattenList(head);

    return head;
}
int main()
{
    return 0;
}