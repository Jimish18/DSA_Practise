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

int getDecimalValue(node* head)
{
    node* temp = head;
    vector<int> bin;

    while(temp != NULL)
    {
        bin.push_back(temp->data);
        temp = temp->next;
    }

    int sum = 0;

    for(int i = 0 ; i < bin.size(); i++)
    {
        sum += bin[i]*pow(2,bin.size()-i-1);
    }

    return sum;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,1);
    insertAtTail(head,0);

    printLnkdLst(head);

    cout<<getDecimalValue(head)<<endl;
    return 0;
}