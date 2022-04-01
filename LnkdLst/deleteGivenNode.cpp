// Problem Statement:=>  Delete Node in a Linked List

// Description:
//     Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.It is guaranteed that the node to be deleted is not a tail node in the list.

// sample :
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

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

void insertAtTail(node* &head,int val)
{
    node* n = new node();
    n->data = val;
    n->next = NULL;
    
    node* temp = head;

    if(head == NULL)
    {
        head = n;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void printLnkdLst(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

void deleteNode(node* nodeToBeDelete) 
{
    node* toDelete = nodeToBeDelete->next;
    nodeToBeDelete->data = nodeToBeDelete->next->data;
    nodeToBeDelete->next = nodeToBeDelete->next->next;
    delete toDelete;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,1);
    insertAtTail(head,0);

    printLnkdLst(head);
    return 0;
}