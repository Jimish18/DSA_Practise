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

int pairSum(node* head) 
{
    node* temp = head;
    vector<int> v;
    int maxi = INT_MIN;
    
    while(temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    
    int n = v.size();
    for(int i = 0 ; i < (n/2) ; i++)
    {
        if((v[i]+v[n-(i+1)])>maxi)
        {
            maxi = v[i]+v[n-(i+1)];
        }
    }
    
    return maxi;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,2);
    // insertAtTail(head,2);
    insertAtTail(head,1);
    cout<<pairSum(head)<<endl;
    
    return 0;
}