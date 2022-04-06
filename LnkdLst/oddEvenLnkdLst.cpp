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

node* oddEvenList(node* head)
{
    vector<int> v;
    vector<int> odd;
    vector<int> even;

    node* temp = head;

    while(temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    
    for(int i = 1 ; i <= v.size() ; i++)
    {
        if(i%2 == 0)
        {
            even.push_back(v[i-1]);
        }
        else
        {
            odd.push_back(v[i-1]);
        }
    }

    node* newHead = NULL;

    for(int i = 0 ; i< odd.size(); i++)
    {
        insertAtTail(newHead,odd[i]);
    }

    for(int i = 0 ; i< even.size(); i++)
    {
        insertAtTail(newHead,even[i]);
    }

    return newHead;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    // insertAtTail(head,2);
    // insertAtTail(head,1);
    // insertAtTail(head,3);
    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // insertAtTail(head,4);
    // insertAtTail(head,7);

    printLnkdLst(head);

    printLnkdLst(oddEvenList(head));

    // oddEvenList(head);

    return 0;
}