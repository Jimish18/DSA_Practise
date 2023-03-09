/*
Question - Add Two Numbers II

Link - https://leetcode.com/problems/add-two-numbers-ii/
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

ListNode* reverseLinkedList(ListNode* &head)
{
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void insertAtTail(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode(val);
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
    ListNode* head1 = reverseLinkedList(l1);
    ListNode* head2 = reverseLinkedList(l2);

    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    ListNode* temp3 = NULL;
    int carry = 0;

    while(temp1 && temp2)
    {
        int value = (temp1->val) + (temp2->val) + carry;

        insertAtTail(temp3,(value%10));
        carry = value/10;
        temp1 = temp1->next;
        temp2 = temp2->next;        
    }

    while(temp1)
    {
        int value = temp1->val + carry;

        insertAtTail(temp3,(value%10));
        carry = value/10;
        temp1 = temp1->next;
    }

    while(temp2)
    {
        int value = temp2->val + carry;

        insertAtTail(temp3,(value%10));
        carry = value/10;
        temp2 = temp2->next;
    }

    while(carry)
    {
        insertAtTail(temp3,(carry%10));
        carry = carry/10;
    }

    return reverseLinkedList(temp3);
}

int main()
{
    return 0;
}