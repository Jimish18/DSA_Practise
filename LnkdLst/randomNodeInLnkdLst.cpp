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

class solution
{
    node* root;
    int count = 0;

    public:

    solution(node* head)
    {
        root = head;
        node* temp = root;

        int x = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            x++;
        }

        count = x;
    }

    int getrandom()
    {
        int n = count;
        int x = rand() % n;

        node* temp = root;

        for(int i = 0 ; i < x ; i++)
        {
            temp = temp->next;
        }

        return temp->data;
    }
};

int main()
{
    node* head = NULL;
    head->insertAtTail(head,0);
    head->insertAtTail(head,1);
    head->insertAtTail(head,2);
    head->insertAtTail(head,3);
    head->insertAtTail(head,4);

    head->printLnkdLst(head);

    solution s(head);
    cout<<s.getrandom()<<endl;

    return 0;
}

