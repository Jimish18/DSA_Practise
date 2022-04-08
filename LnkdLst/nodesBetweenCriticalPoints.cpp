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

    vector<int> nodesBetweenCriticalPoints(node* head) 
    {
        vector<int> v;
        if(head == NULL || head->next == NULL || head->next->next == NULL || head->next->next->next == NULL)
        {
            v.push_back(-1);
            v.push_back(-1);

            return v;
        }

        node* front = head;
        // node* temp = head;
        vector<int> index;
        node* back = head->next;
        int count = 2;

        while(back->next != NULL)
        {
            if(back->data > front->data && back->data > back->next->data)
            {
                index.push_back(count);
            }
            if(back->data < front->data && back->data < back->next->data)
            {
                index.push_back(count);
            }

            front = front->next;
            back = back->next;
            count++;
        }

        if(index.size()<2)
        {
            v.push_back(-1);
            v.push_back(-1);

            return v;
        }

        int mini = INT_MAX;
        int max = index[index.size()-1] - index[0];

        for(int i = 0 ; i < index.size()-1; i++)        //Double loop for comparing values will be take more time,
        {                                               //So single will take comparetively less time 

            if(index[i+1]-index[i] < mini)
            {
                mini = index[i+1]-index[i];
            }

            // for(int j = i+1 ; j < index.size(); j++)
            // {
                
            // }
        }

        // cout<<mini<<" "<<(index[index.size()-1] - index[0])<<endl;

        v.push_back(mini);
        v.push_back(max);

        return v;
    }
};

int main()
{
    node* head = NULL;
    // head->insertAtTail(head,1);
    // head->insertAtTail(head,3);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,3);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,2);    
    // head->insertAtTail(head,7);

    head->insertAtTail(head,5);
    head->insertAtTail(head,3);
    head->insertAtTail(head,1);
    head->insertAtTail(head,2);
    head->insertAtTail(head,5);
    head->insertAtTail(head,1);
    head->insertAtTail(head,2);

    // head->insertAtTail(head,1);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,1);

    // head->insertAtTail(head,2);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,1);
    // head->insertAtTail(head,3);

    head->printLnkdLst(head);
    
    Solution s;

    for(int i = 0 ; i < s.nodesBetweenCriticalPoints(head).size() ; i++)
    {
        cout<<s.nodesBetweenCriticalPoints(head)[i]<<" ";
    }
    
    return 0;
}