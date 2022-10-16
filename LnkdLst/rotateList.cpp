/*
Question - Rotate List

Link - https://leetcode.com/problems/rotate-list/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

int lengthOfList(ListNode* head)
{
    int length = 0;

    ListNode* temp = head;

    while(temp)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

ListNode* rotateRight(ListNode* head, int k) 
{
    if(!head)
    {
        return NULL;
    }
    int n = lengthOfList(head);
    int count = k%n;
    if(count == 0)
    {
        return head;
    }
    count = n-count;
    int count2 = 1;
    ListNode* temp = head;
    ListNode* newHead;

    while((count2 < count) && temp)
    {
        count2++;
        temp = temp->next;
    } 

    
    newHead = temp->next;
    ListNode* temp2 = newHead;

    while(temp2->next)
    {   
        temp2 = temp2->next;
    }

    temp2->next = head;
    temp->next = NULL;

    return newHead;
}

void printList(ListNode* head)
{
    ListNode* temp = head;

    while(temp)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main()
{
    ListNode* head =new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5); 

    printList(head);   
    cout<<endl;
    printList(rotateRight(head,4));
    return 0;
}