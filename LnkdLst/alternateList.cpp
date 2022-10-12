/*
Question - Alternate List

Link - 
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

ListNode* alternateList(ListNode* root)
{
    ListNode* fast = root;
    ListNode* slow = root;

    while(fast->next != NULL || fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* prev = NULL;
    ListNode* cur = slow->next;
    ListNode* next;
    slow->next = NULL;

    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev ;
        prev = cur;
        cur = next;
    }

    ListNode* temp = root;
    ListNode* temp2 = prev;

    while(temp != NULL)
    {
        temp->next = temp2;
        temp2 = temp2->next;
    }



    
}

int main()
{
    return 0;
}