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

int nodesToNumber(ListNode* l1)
{
    ListNode* temp = l1;
    int i = 0;
    int number = 0;
    while(temp != NULL)
    {
        number+= (pow(10,i)*(temp->data));
        i++;
        temp = temp->next;
    }

    return number;

}

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
    
}

int main()
{
    ListNode* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    ListNode* head2 = NULL;
    insertAtTail(head,4);
    insertAtTail(head,5);

    cout<<nodesToNumber(head)<<endl;


    return 0;
}