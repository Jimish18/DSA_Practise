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

node* appendLastKNodes(node* &head,int k)
{
    node* temp = head;
    node* join = head;
    int count = lengthOfLnkdLst(head) - k;

    while(count>1)
    {
        count--;
        temp = temp->next;
    }

    node* newHead = temp->next;
    temp->next = NULL;

    node* tempjoin = newHead;

    while(tempjoin->next != NULL)
    {
        tempjoin = tempjoin->next;
    }

    tempjoin ->next = head;

    return newHead;
}


int main()
{
    node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,8);
    insertAtTail(head,10);
    insertAtTail(head,12);
    insertAtTail(head,14);
    insertAtHead(head,0);

    printLnkdLst(head);

    cout<<lengthOfLnkdLst(head)<<endl;

    printLnkdLst(appendLastKNodes(head,1));

    return 0;
}