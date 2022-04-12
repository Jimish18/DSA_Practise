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
        int divide = l/k;
        int modulo = l%k;

        node* temp = head;
        node* temphead = head;

        if(l>k)
        {
            int count;

            for(int i = 0 ; i < k ; i++)
            {
                count = divide;

                if(modulo > 0)
                {
                    count = count + 1 ;
                    modulo--;
                }                
                int x = 1;

                while(x < count)
                {
                    temp = temp->next;
                    x++;
                }

                node* newhead = temp->next;
                temp->next = NULL;
                v.push_back(head);
                head = newhead;
            }
        }

        for(int i = 0 ; i < k ; i++)
        {
            v[i]->printLnkdLst(v[i]); 
        }

        return v;
    }
};

int main()
{
    node* head = NULL;
    head->insertAtTail(head,1);
    head->insertAtTail(head,2);
    head->insertAtTail(head,3);
    head->insertAtTail(head,4);
    head->insertAtTail(head,5);
    head->insertAtTail(head,6);
    head->insertAtTail(head,7);
    head->insertAtTail(head,8);
    head->insertAtTail(head,9);
    head->insertAtTail(head,10);


    head->printLnkdLst(head);

    cout<<head->lengthOfLnkdLst(head)<<endl;

    Solution s;
    s.splitListToParts(head,3);

    return 0;
}
