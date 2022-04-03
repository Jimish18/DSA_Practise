/*
Problem Statement :-> 
    Given head, the head of a linked list, determine if the linked list has a cycle in it.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.
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

void createCycle(node* &head,int index)
{
    node* temp = head;
    node* strtcycle;

    int count = 0;

    while(temp->next != NULL)
    {
        count++;
        if(count == index)
        {
            strtcycle = temp;
        }
        temp = temp->next;
    }

    temp->next = strtcycle;
}

bool detectCycle(node* head)
{
    node* slow = head;
    node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,0);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,8);
    insertAtTail(head,10);
    insertAtTail(head,12);
    // createCycle(head,4);
    cout<<detectCycle(head)<<endl;

    return 0;
}