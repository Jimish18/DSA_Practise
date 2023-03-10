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
    stack<long long> st;
    ListNode* temp = newHead;

    while(temp)
    {
        if(!st.empty() && st.top() > temp->val)
        {
            result.insert(result.begin(),st.top());
            st.push(temp->val);
        }
        else
        {
            while(!st.empty() && st.top() <= temp->val) 
            {
                st.pop();
            }

            if(st.empty())
            {
                result.insert(result.begin(),0);
            } 
            else
            {
                result.insert(result.begin(),st.top());
            }

            st.push(temp->val);
        }

        temp = temp->next;
    }

    return result;
}

int main()
{
    return 0;
}