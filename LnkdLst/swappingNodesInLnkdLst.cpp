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

int lenghtOfLnkdlst(node* head)
{
    int count = 0;
    node* temp = head;
    
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    return count;
}

node* swapNodes(node* head, int k) 
{
    node* front = head;
    node* back = head;
    int countF = 0;
    int countB = 0;
    int a,b;
    int l = lenghtOfLnkdlst(head);

    while(countF != (k-1))
    {
        countF++;
        front = front->next;
    }

    while(countB != (l-k))
    {
        countB++;
        back = back->next;
    }

    a = front->data;
    b = back->data;

    front->data = b;
    back->data = a;

    return head;
}

int main()
{
    node* head = NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // insertAtTail(head,5);
    insertAtTail(head,100);
    insertAtTail(head,90);
    printLnkdLst(head);   

    printLnkdLst(swapNodes(head,2));

    
    return 0;
}