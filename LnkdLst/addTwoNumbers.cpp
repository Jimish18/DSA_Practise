/*
Question - Add Two Numbers

Link - https://leetcode.com/problems/add-two-numbers/
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode* next;
};

void insertAtTail(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode();
    newNode->data = val;
    newNode->next = NULL;
    ListNode* temp = head;

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{   

    ListNode* temp1 = l1;    

    ListNode* temp2 = l2;

    ListNode* head3 = NULL;

    int carry = 0;

    while(temp1 != NULL && temp2 != NULL)
    {
        int data = (temp1->data) + (temp2->data) + carry;

        
        insertAtTail(head3,data%10);

        carry = data/10;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while(temp1 != NULL)
    {
        int data = temp1->data + carry;

        insertAtTail(head3,data%10);

        carry = data/10;

        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        int data = temp2->data + carry;

        insertAtTail(head3,data%10);

        carry = data/10;

        temp2 = temp2->next;
    }

    if(carry != 0)
    {
        insertAtTail(head3,carry%10);
        carry = carry/10;
    }

    return head3;
}

void printLnkdLst(ListNode* l)
{
    ListNode* temp = l;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

int main()
{
    ListNode* head = NULL;
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    ListNode* head2 = NULL;
    insertAtTail(head2,9);
    insertAtTail(head2,9);
    insertAtTail(head2,9);
    insertAtTail(head2,9);

    printLnkdLst(head);
    printLnkdLst(head2);

    printLnkdLst(addTwoNumbers(head,head2));


    return 0;
}