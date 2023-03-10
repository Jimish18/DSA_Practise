/*
Question - Next Greater Node In Linked List

Link - https://leetcode.com/problems/next-greater-node-in-linked-list/
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


vector<int> nextLargerNodes(ListNode* head) 
{
    vector<int> result;

    ListNode* newHead = reverseLinkedList(head);
    long long maxValue = newHead->val;
    ListNode* temp = newHead;

    while(temp)
    {
        if(temp->val < maxValue)
        {
            result.insert(result.begin(),maxValue);
        }
        else
        {
            result.insert(result.begin(),0);
            maxValue = temp->val;
        }

        temp = temp->next;
    }

    return result;
}

int main()
{
    return 0;
}