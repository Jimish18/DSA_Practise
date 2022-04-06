/*
Problem Statement :-> You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

Example1 :
Input: head = [2,1,5]
Output: [5,5,0]


Example2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]


Warning -->>Using this code, time limit exceeds so we can use stack data structure to reduce time 
            But i hadn't learnt stack data structure yet. so I will do it with it's approach after i will learn
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
    node* newNode = new node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(node* &head,int val)
{
    node* newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    node* temp = head;

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

vector<int> nextLargerNodes(node* head)
{
    node* temp = head;
    node* search = head->next;
    vector<int> v;
    vector<int> r;

    while(temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    for(int i = 0 ; i < (v.size()-1) ;i++)
    {
        for(int j = i+1 ; j < v.size() ; j++)
        {
            if(v[j] > v[i])
            {
                r.push_back(v[j]);
                break;
            }
            if( j == v.size()-1 && v[j] <= v[i])
            {
                r.push_back(0);
            }
        }
    }

    r.push_back(0);

    
}

int main()
{
    node* head = NULL;
    // insertAtTail(head,2);
    // insertAtTail(head,7);
    // insertAtTail(head,4);
    // insertAtTail(head,3);
    // insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,5);
    printLnkdLst(head);

    nextLargerNodes(head);

    return 0;
}