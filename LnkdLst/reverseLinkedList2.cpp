/*
Question - Reverse Linked List II

Link - https://leetcode.com/problems/reverse-linked-list-ii/
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

ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    if(!head || !head->next) return head;

    int pos = 1;
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* temp = dummy;    

    while(temp && pos != left)
    {
        temp = temp->next;
        pos++;
    }

    ListNode* conn = temp;
    ListNode* connHead = temp->next;

    while(temp && (pos-1) != right)
    {
        temp = temp->next;
        pos++;
    }

    ListNode* conntail = temp->next;
    temp->next = NULL;

    conn->next = reverseList(connHead);
    connHead->next = conntail;
    
    return dummy->next;
}

int main()
{
    return 0;
}