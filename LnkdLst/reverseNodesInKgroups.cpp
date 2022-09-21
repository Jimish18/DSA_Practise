/*
Question - reverse nodes in k groups 

Link - https://leetcode.com/problems/reverse-nodes-in-k-group/
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

void insertAtHead(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = NULL;
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

int lengthOfLnkdLst(ListNode* head)
{
    ListNode* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

ListNode* reverseNodesKGroup(ListNode* head, int k,int ct) 
{
    int count = 0;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;

    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL && ct >= k)
    {
        head->next = reverseNodesKGroup(next,k,(ct-k));
    }
    else
    {
        head->next = next;
    }

    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    int l = lengthOfLnkdLst(head);
    if(l < k)
    {
        return head;
    }
    return reverseNodesKGroup(head,k,(l-k));
}


int main()
{
    ListNode* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    // insertAtTail(head,6);

    printLnkdLst(reverseKGroup(head,2));

    return 0;
}