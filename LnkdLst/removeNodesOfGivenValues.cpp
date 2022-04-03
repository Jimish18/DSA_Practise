/*
Problem Statement:-> 
    Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example2:
Input: head = [], val = 1
Output: []

Example3:
Input: head = [7,7,7,7], val = 7
Output: []
*/

// NOTE : Solved this Question Using recursion method;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head)
        {
            return head;
        }
        
        if(head->val == val)
        {
            return removeElements(head->next,val);
        }
        
        ListNode* temp = head;
        
        while(temp && temp->next)
        {
            if(temp->next->val == val)
            {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }           
            
        }
        
        return head;
    }
};