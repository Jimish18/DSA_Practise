#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

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

};

class Solution
{
    public:

    node* swapPairs(node* head)
    {
        if(!head)
        {
            return NULL;
        }

        node* front = head;
        node* back = head->next;

        // int a,b;

        while(front != NULL && back != NULL)
        {
            int temp = front->data;
            front->data = back->data;
            back->data = temp;

            if(back->next == NULL)
            {
                break;
            }

            front = back->next;
            back = back->next->next;
        }

        return head;
    }
};

int main()
{
    node* head = NULL;
    head->insertAtTail(head,1);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,3);
    // head->insertAtTail(head,4);
    // head->insertAtTail(head,5);
    // head->insertAtTail(head,6);

    head->printLnkdLst(head);

    Solution s;
    head->printLnkdLst(s.swapPairs(head));
    return 0;
}