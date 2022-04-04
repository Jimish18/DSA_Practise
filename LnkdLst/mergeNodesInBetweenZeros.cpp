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
/*
Code-1:

node* mergeNodes(node* &head)
{
    node* temp = head->next;
    int sum = 0;
    vector<int> v;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            sum+=temp->data;
            temp = temp->next;
        }

        v.push_back(sum);
        sum = 0;
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL)
    {
        node* toDelete = temp;
        temp = temp ->next;
        delete toDelete;
    }

    node* newHead = NULL;
    for(int i = 0 ; i < v.size() ; i++)
    {
        insertAtTail(newHead,v[i]);
    }

    return newHead;
}
*/

// Code- 2
node* mergeNodes(node* &head)
{
    node* cr = head->next;
    node* prev = head->next;
    int sum = 0;

    while(cr != NULL)
    {
        while(cr->data != 0)
        {
            sum += cr->data;
            cr = cr->next;
        }

        cr = cr->next;
        prev->data = sum;
        sum = 0;
        prev->next = cr;
        prev = prev->next;
    }
    

    return head->next;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,0);
    insertAtTail(head,3);
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,0);

    printLnkdLst(mergeNodes(head));
    return 0;
}