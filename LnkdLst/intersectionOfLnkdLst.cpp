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
    node* newNode = new node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(node* &head,int val)
{
    node* newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    node* temp = head;

    if(head == NULL)
    {
        head = newNode;

        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp -> next = newNode;

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

void makeIntersection(node* &head1,node* &head2,int pos)
{
    node* temp1 = head1;
    node* temp2 = head2;

    int count = 1;

    while(count < pos)
    {
        temp1 = temp1->next;
        count++;
    }

    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int lengthOfLnkdLst(node* head)
{
    node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void removeIntersection(node* head1,node* head2)
{
    node* temp1;
    node* temp2;

    int l1 = lengthOfLnkdLst(head1);
    int l2 = lengthOfLnkdLst(head2);
    
    int d;

    if(l1>l2)
    {
        d = l1-l2; 
        temp1 = head1;
        temp2 = head2;       
    }
    else
    {
        d = l2-l1;
        temp1 = head2;
        temp2 = head1;
    }
    cout<<d<<endl;

    while(d>0)
    {
        temp1 = temp1->next;
        d--;
    }

    while(temp1->next != temp2->next)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp2->next = NULL;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    
    insertAtTail(head1,0);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,8);
    insertAtTail(head1,10);
    insertAtTail(head1,12);
    insertAtTail(head1,14);

    insertAtTail(head2,22);
    insertAtTail(head2,24);    

    printLnkdLst(head1);
    printLnkdLst(head2);
    makeIntersection(head1,head2,6);

    printLnkdLst(head2);

    removeIntersection(head1,head2);

    printLnkdLst(head2);
    
}