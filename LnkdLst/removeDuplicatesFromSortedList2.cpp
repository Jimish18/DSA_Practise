/*
Question - Remove Duplicates from Sorted List II

Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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


ListNode* deleteDuplicates(ListNode* head) 
{
    if(!head || !head->next) return head;
    ListNode* temp = new ListNode();

    temp->next = head; 

    ListNode* front = head->next;
    ListNode* back = head;
    ListNode* pointer = temp;

    while(front)
    {
        if(front->val == back->val)
        {
            while(front && front->val == back->val)
            {
                front = front->next;
            }

            pointer->next = front;
            back = front;
            front = front->next;
        }
        else
        {
            front = front->next;
            back = back->next;
            pointer = pointer->next;
        }
    }

    return temp->next;
    
}

int main()
{
    return 0;
}