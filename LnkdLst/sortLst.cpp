/*
Problem Statement :-> Given the head of a linked list, return the list after sorting it in ascending order.

example1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

example2 :
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

example3:
Input: head = []
Output: []
*/

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

    void merge(vector<int> &v,int r,int mid,int l)
    {
        vector<int > a;
        vector<int > b;
        

        for(int i = 0; i < mid-r+1; i++ )
        {
            a.push_back(v[r+i]);
        }
        for(int i = 0; i < l-mid; i++)
        {
            b.push_back(v[mid+1+i]);
        }

        int i = 0;
        int j = 0;
        int k = r;

        while(i < a.size() && j < b.size())
        {
            if(a[i] < b[j])
            {            
                v[k] = a[i];
                i++;k++;
            }
            else
            {
                v[k] = b[j];
                j++;k++;
            }
        }

        while(i < a.size())
        {
            v[k] = a[i];
            i++;k++;    
        }

        while(j < b.size())
        {
            v[k] = b[j];
            j++;k++;
        }

    }

    void mergeSort(vector<int> &v, int r , int l)
    {
        if(r<l)
        {
            int mid = (r+l)/2;

            mergeSort(v,r,mid);
            mergeSort(v,mid+1,l);

            merge(v,r,mid,l);
        }
    }
    
    node* sortList(node* head) 
    {
        vector<int> v;
        node* temp = head;

        while(temp != NULL)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }

        mergeSort(v,0,v.size()-1);

        // node* newHead = NULL;
        temp = head;

        for(int i = 0 ; i < v.size() ; i++)
        {
            // newHead->insertAtTail(newHead,v[i]);
            temp->data = v[i];
            temp = temp->next;
            // cout<<v[i]<<" ";
        }
        // cout<<endl;

        // temp = head;

        // while(temp != NULL)
        // {
        //     node* toDelete = temp;
        //     temp = temp->next;
        //     delete toDelete;
        // }

        return head;
    }
};

int main()
{
    node* head = NULL;

    for(int i = 10 ; i > 0 ; i--)
    {
        head->insertAtTail(head,i);
    }

    head->printLnkdLst(head);

    Solution s;
    head->printLnkdLst(s.sortList(head));


    return 0;
}