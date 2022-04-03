/*
Problem Statement :-> Given the head of a singly linked list, return true if it is a palindrome.

example 1:
Input: head = [1,2,2,1]
Output: true

example2:
Input: head = [1,2]
Output: false
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

bool isPalindrome(node* head) 
{
    if(!head)
    {
        return NULL;
    }
    
    node* temp = head;
    vector<int> v;
    
    while(temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    bool flag;

    for(int i = 0 ; i < (v.size()/2) ; i++)
    {
        if(v[i] != v[v.size()-(i+1)])
        {
            flag = false;
            return flag;
        }
        else
        {
            flag = true;
        }
    }

    return flag;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    // insertAtTail(head,2);
    insertAtTail(head,1);
    printLnkdLst(head);
    cout<<isPalindrome(head)<<endl;
    
    return 0;
}