/*
Problem Statement :-> 
    You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

Example1: 
Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

Example2:
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.

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

node* mergeInBetween(node* list1, int a, int b, node* list2) 
{
    node* temp2 = list2;

    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    node* front = list1;
    node* back = list1;
    int countF = 0;
    int countB = 0;

    while(countB < b)
    {
        if(countF < a-1)
        {
            front = front->next;
            countF++;
        }

        back = back->next;
        countB++;
    }

    node* huehue = front->next->next;
    front->next = list2;
    temp2->next = back->next;
    back = back->next;

    while(huehue != back)
    {
        node* toDelete = huehue;
        huehue = huehue->next;
        delete toDelete;
    }    

    return list1;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    insertAtTail(head1,0);
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    // insertAtTail(head1,6);

    insertAtTail(head2,1000000);
    insertAtTail(head2,1000001);
    insertAtTail(head2,1000002);
    // insertAtTail(head2,1000003);
    // insertAtTail(head2,1000004);

    printLnkdLst(head1);
    printLnkdLst(head2);

    

    printLnkdLst(mergeInBetween(head1,3,4,head2));
    // mergeInBetween(head1,3,4,head2);
    return 0;
}