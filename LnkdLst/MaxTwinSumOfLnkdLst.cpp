#include <bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode* next;
};

int pairSum(ListNode* head) 
{
    int maxi = INT_MIN;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow->next;
    slow->next = NULL;

    ListNode* prev = NULL;
    ListNode* cur = fast;
    ListNode* next;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    ListNode* temp = prev;
    slow = head;

    while(temp && slow)
    {
        maxi = max(maxi,(temp->val + slow->val));
        temp = temp->next;
        slow = slow->next;
    }

    return maxi;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,2);
    // insertAtTail(head,2);
    insertAtTail(head,1);
    cout<<pairSum(head)<<endl;
    
    return 0;
}