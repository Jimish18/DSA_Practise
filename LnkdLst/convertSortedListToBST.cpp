/*
Question - Convert Sorted List to Binary Search Tree

Link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* sortedListToBST(ListNode* head) 
{    
    if(!head) return NULL;
    ListNode* slow = head;
    ListNode* fast = head;

    if(!head->next) return new TreeNode(head->val);
    if(head->next && !head->next->next) slow = head->next;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }   
    
    TreeNode* root = new TreeNode(slow->val);

    fast = head;

    while(fast->next != slow)
    {
        fast = fast->next;
    }

    fast->next = NULL;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);


    return root;

}

int main()
{
    return 0;
}