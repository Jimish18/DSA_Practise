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

ListNode* reorderList(ListNode* root)
{
    ListNode* fast = root;
    ListNode* slow = root;

    while(fast->next && fast->next->next)
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

    // printList(root);
    // printList(prev);


    ListNode* temp = root;
    ListNode* temp2 = prev;
    ListNode* tempRoot = new ListNode(0);
    ListNode* temp3 = tempRoot;
    bool check = false;

    while(temp2)
    {
        if(check)
        {
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;           
        }
        else
        {
            temp3->next = temp;
            temp = temp->next;
            temp3 = temp3->next;
        }

        check = !check;

    }

    if(temp)
    {
        temp3->next = temp;
        temp3 = temp3->next;
        temp = temp->next;
    }

    temp3->next = NULL;


    return tempRoot->next;
    
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

    cout<<endl<<"after"<<endl;
    printList(reorderList(root));

    // ListNode* temp = reorderList(root);

    

    return 0;
}