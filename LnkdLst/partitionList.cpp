/*
Question - Partition List

Link - https://leetcode.com/problems/partition-list/
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

ListNode* partition(ListNode* head, int x) 
{
    if(!head || !head->next) return head;

    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* temp = dummy;
    ListNode* temp2 = dummy;

    while(temp2 && temp2->next && temp2->next->val < x) 
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    while(temp)
    {
        if(temp->next && temp->next->val < x)
        {
            ListNode* connection = temp->next->next;
            temp->next->next = temp2->next;
            temp2->next = temp->next;
            temp->next = connection;
            temp2 = temp2->next;
        }
        else
        {
            temp = temp->next;
        }
        
    }
    return dummy->next;
}

int main()
{
    return 0;
}