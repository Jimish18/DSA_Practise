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

void insertAtTail(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode(val);    
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

void printList(ListNode* root)
{
    ListNode* temp = root;

    while(temp)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }   
    cout<<"NULL"<<endl;
}

void reorderList(ListNode* root)
{
    ListNode* fast = root;
    ListNode* slow = root;

    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(slow == fast)
    {
        return;
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


    ListNode* p1 = root;
    ListNode* p2 = prev;
    ListNode* temp;  

    while(p1 && p2)
    {
        temp = p2;
        p2 = p2->next;
        temp->next = p1->next;
        p1->next = temp;
        temp = temp->next;
        p1 = temp;
    }

        
}



int main()
{
    ListNode* root = NULL;
    insertAtTail(root,1);
    insertAtTail(root,2);
    insertAtTail(root,3);
    insertAtTail(root,4);
    // insertAtTail(root,5);

    cout<<"before"<<endl;
    printList(root);

    reorderList(root);

    cout<<endl<<"after"<<endl;
    printList(root);

    // ListNode* temp = reorderList(root);

    

    return 0;
}