/*
Problem Statement :-> 
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Example1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 


Example2:
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

Example3:
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.

*/

#include <bits/stdc++.h>
using namespace std;


// class node
// {
//     public:
//     int data;
//     node* next;

//     void insertAtHead(node* &head,int val)
//     {
//         node* newNode = new node();
//         newNode->data = val;
//         newNode->next = head;
//         head = newNode;
//     }

//     void insertAtTail(node* &head,int val)
//     {
//         node* newNode = new node();
//         newNode->data = val;
//         newNode->next = NULL;
//         node* temp = head;

//         if(head == NULL)
//         {
//             head = newNode;

//             return;
//         }

//         while(temp->next != NULL)
//         {
//             temp = temp->next;
//         }

//         temp -> next = newNode;

//     }

//     void printLnkdLst(node* head)
//     {
//         node* temp = head;

//         while(temp != NULL)
//         {
//             cout<<temp->data<<"->";
//             temp = temp->next;
//         }

//         cout<<"NULL"<<endl;
//     }

//     int lengthOfLnkdLst(node* head)
//     {
//         node* temp = head;
//         int count = 0;

//         while(temp != NULL)
//         {
//             count++;
//             temp = temp->next;
//         }

//         return count;
//     }
// };


// Brute Force Approach
// class Solution 
// {
//     public:
    
//     node* deleteMiddle(node* head) 
//     {
//         if(head == NULL || head->next == NULL)
//         {
//             return NULL;
//         }
//         node* temp = head;
//         int count = 1;
//         int l = head->lengthOfLnkdLst(head);

//         while(temp != NULL && count < l/2)
//         {
//             temp = temp->next;
//             count++;
//         }

//         node* toDelete = temp->next;
//         temp->next = temp->next->next;
//         delete toDelete;

//         return head;
//     }
// };

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(slow == fast && !fast->next)
    {
        return NULL;
    }

    if(slow != fast && !fast->next)
    {
        fast = slow;
        slow = head;

        while(slow->next != fast)
        {
            slow = slow->next;
        }
    }

    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
}

int main()
{
    ListNode* head = NULL;
    // head->insertAtTail(head,0);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,4);
    // head->insertAtTail(head,6);
    // head->insertAtTail(head,8);
    // head->insertAtTail(head,10);
    // head->insertAtTail(head,12);

    // head->insertAtTail(head,1);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,3);
    // head->insertAtTail(head,4);

    head->insertAtTail(head,2);
    // head->insertAtTail(head,1);

    head->printLnkdLst(head);

    cout<<head->lengthOfLnkdLst(head)<<endl;

    Solution s;
    head->printLnkdLst(s.deleteMiddle(head));

    return 0;
}