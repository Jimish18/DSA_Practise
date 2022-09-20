/*
Question - Remove Nth Node from the end of the list

Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertAtTail(ListNode* &head,int val)
{
    ListNode* n = new ListNode(val);    
    // n->next = NULL;
    
    ListNode* temp = head;

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


ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* front = head;
    ListNode* back = head;

    while(n-- > 0)
    {
        front = front->next;
    }

    if(front == NULL)
    {
        ListNode* toDelete = back;
        head = back->next;
        delete toDelete;
        return head;
    }

    while(front->next != NULL)
    {
        front = front->next;
        back = back->next;
    }

    ListNode* toDelete = back->next;
    back->next = back->next->next;
    delete toDelete;

    return head;
}

void printLnkdLst(ListNode* head)
{
    ListNode* temp = head;

    while(temp != NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

int main()
{
    ListNode* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // insertAtTail(head,7);

    printLnkdLst(head);

    printLnkdLst(removeNthFromEnd(head,1));
    return 0;
}