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

    int lengthOfLnkdLst(node* head)
    {
        node* temp = head;
        int count = 0;

        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        return count;
    }
};

class Solution 
{
    public:

    vector<node*> splitListToParts(node* head, int k) 
    {
        vector<node*> v;
        int l = head->lengthOfLnkdLst(head);
        node* temp = head;

        if(k >= l)
        {
            for(int i = 0 ; i < k; i++)
            {
                if(temp == NULL)
                {
                    v.push_back(temp);
                    continue;
                }
                else
                {
                    node* singleNode = temp;
                    temp = temp ->next;
                    singleNode->next = NULL;
                    v.push_back(singleNode);
                }
            }
        }  
        else
        {
            
        }

        for(int i = 0; i < k ; i++)
        {
            v[i]->printLnkdLst(v[i]);
        }

        return v;      
    }
};

int main()
{
    node* head = NULL;
    // head->insertAtTail(head,0);
    head->insertAtTail(head,1);
    head->insertAtTail(head,2);
    head->insertAtTail(head,3);
    // head->insertAtTail(head,4);
    // head->insertAtTail(head,5);

    head->printLnkdLst(head);

    cout<<head->lengthOfLnkdLst(head)<<endl;

    Solution s;
    s.splitListToParts(head,3);
    return 0;
}
