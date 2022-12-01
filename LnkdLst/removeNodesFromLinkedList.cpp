/*
Question - Remove Nodes From Linked List

Link - https://leetcode.com/problems/remove-nodes-from-linked-list/
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

ListNode* reverseList(ListNode* &head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;

    while(curr)
    {
        next = curr->next;        
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode* removeNodes(ListNode* head) 
{
    ListNode* newHead = reverseList(head);

    ListNode* back = newHead;
    ListNode* front = newHead->next;

    while(front)
    {
        if(front->val < back->val)
        {
            ListNode* toDelete = front;
            front = front->next;
            back->next = front;
            delete toDelete;
        }
        else
        {
            front = front->next;
            back = back->next;
        }
    }

    ListNode* newHead2 = reverseList(newHead);

    return newHead2;
        
}



int main()
{
    return 0;
}