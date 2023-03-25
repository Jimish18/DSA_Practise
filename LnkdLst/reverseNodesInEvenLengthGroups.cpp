/*
Question - Reverse Nodes In Even Length Groups

Link - https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
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

ListNode* reverseGroup(ListNode* &head)
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

ListNode* reverseEvenLengthGroups(ListNode* head) 
{
    ListNode* temp = new ListNode();
    temp->next = head;

    ListNode* prev = temp;

    for(int i = 1 ; i < 1e5 && head; i++)
    {
        ListNode* tail = head;
        ListNode* nextHead;

        int count = 1;
        while(count < i && tail && tail->next)
        {
            tail = tail->next;
            count++;
        }

        nextHead = tail->next;

        if(count%2 == 0)
        {
            tail->next = NULL;
            prev->next = reverseGroup(head);
            prev = head;
            head->next = nextHead;
            head = nextHead;
        }
        else
        {
            prev = tail;
            head = nextHead;
        }
    }
    

    return temp->next;
}

int main()
{
    return 0;
}