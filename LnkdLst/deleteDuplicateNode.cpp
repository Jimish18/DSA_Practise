/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

void insertAtHead(node* &head,int val)
{
    node* n = new node();
    n->data = val;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head,int val)
{
    node* n = new node();
    n->data = val;
    n->next = NULL;
    
    node* temp = head;

    if(head == NULL)
    {
        head = n;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void printLnkdLst(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}




node* deleteDuplicates(node* &head) 
{
    if(!head)       //Important case to add when head is NULL
    {
        return NULL;
    }

    node* temp = head;

    while(temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        if(temp->next == NULL)
        {
            return head;
        }

        if(temp->data != temp->next->data)
        {
            temp = temp->next;
        }
    }

    return head;

}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,4);
    printLnkdLst(head);

    printLnkdLst(deleteDuplicates(head));
    return 0;
}
