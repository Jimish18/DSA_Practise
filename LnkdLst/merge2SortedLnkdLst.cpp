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

node* merge2SortedLnkdLst(node* &head1,node* &head2)
{
    node* dummy = new node;
    node* temp3 = dummy;
    // dummy->data = NULL;
    
    int l1 = lengthOfLnkdLst(head1);
    int l2 = lengthOfLnkdLst(head2);

    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data >= temp2->data)
        {
            temp3->next = temp2;
            temp2 = temp2->next;            
        }
        else
        {
            temp3->next = temp1;
            temp1 = temp1->next;
        }        

        temp3 = temp3->next;
    }

    // while(temp1 != NULL)
    // {
    //     temp3->next = temp1;
    //     temp3 = temp3->next;
    //     temp1 = temp1->next;
    // }

    // while(temp2 != NULL)
    // {
    //     temp3->next = temp2;
    //     temp3 = temp3->next;
    //     temp2 = temp2->next;
    // }

    if(l1>l2)
    {
        temp3->next = temp1;
    }
    else
    {
        temp3->next = temp2;
    }

    return dummy->next;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    insertAtTail(head1,0);
    insertAtTail(head1,3);
    insertAtTail(head1,5);
    insertAtTail(head1,7);

    insertAtTail(head2,2);
    insertAtTail(head2,4);
    insertAtTail(head2,6);
    insertAtTail(head2,10); 
    insertAtTail(head2,12);
    insertAtTail(head2,15);  

    printLnkdLst(merge2SortedLnkdLst(head1,head2));

    return 0;
}