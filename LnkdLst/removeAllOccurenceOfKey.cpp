/*
Given a linked list and a key, remove all occurrences of the key from the Linked List. 
Return the head of the resultant list.

Example
Linked List: 1→2→3→2→4→7→2
Key: 2
After removal: 1→3→4→7
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

void insertAtHead(node* &head,int val)
{
    node* n = new node();
    n->data = val;
    n->next = head;
    head = n;
}

void insertNodeAtEnd(node* &head,int val)
{
    node* n = new node();
    n->data = val;
    n->next = NULL;

    node* temp = head;
    
    if(head == NULL)
    {
        insertAtHead(head,val);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;        

    }

}

void prntLnkdLst(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

node* removeOccurrence(node* &head,int key)
{
    node* random = new node();
    random->data = 1;
    random->next = head;

    node* temp = random;

    while(temp->next != NULL)
    {
        if(temp->next->data == key)
        {
            node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else
        {
            temp = temp->next;
        }        
    }

    node* newHead = random->next;
    delete random;

    return newHead;
}

int main()
{
    node* head = NULL;
    insertNodeAtEnd(head,2);
    insertNodeAtEnd(head,2);
    insertNodeAtEnd(head,4);
    insertNodeAtEnd(head,2);
    insertNodeAtEnd(head,2);
    insertNodeAtEnd(head,10);
    insertNodeAtEnd(head,12);
    insertNodeAtEnd(head,14);
    insertNodeAtEnd(head,2);
    prntLnkdLst(head);
    prntLnkdLst(removeOccurrence(head,2));
    return 0;
}