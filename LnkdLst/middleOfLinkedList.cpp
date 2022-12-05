/*
Question - Middle of Linked List

Link - https://leetcode.com/problems/middle-of-the-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach O(2N)
//     int lengthOfLnkdLst(ListNode* head)
//     {
//         ListNode* temp = head;
        
//         int count = 0;
//         while(temp != NULL)
//         {
//             count++;
//             temp = temp->next;
//         }
        
//         return count;
//     }
//     ListNode* middleNode(ListNode* head) 
//     {
//         int d = (lengthOfLnkdLst(head)/2);
//         ListNode* temp = head;
        
//         while(d>0)
//         {
//             temp = temp->next;
//             --d;
//         }
        
//         return temp;
//     }
    
// Standard Method O(N)
ListNode* middleNode(ListNode* head) 
{
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main()
{
    return 0;
}