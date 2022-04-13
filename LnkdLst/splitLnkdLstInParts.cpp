/*
Problem Statement :->
    Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

Example1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

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

        if(l>=k)
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
                v.push_back(temphead);
                temphead = newhead;
                temp = newhead;
                // v[i]->printLnkdLst(v[i]);
            }
        }
        else
        {
            for(int i = 0 ; i < k ; i++)
            {
                if(modulo > 0)
                {
                    node* newhead = temp->next;
                    temp->next = NULL;
                    v.push_back(temp);
                    temp = newhead;
                    modulo--;
                }
                else
                {
                    v.push_back(NULL);
                }
            }
        }

        return v;
    }
};

int main()
{
    node* head = NULL;
    head->insertAtTail(head,0);
    // head->insertAtTail(head,1);
    // head->insertAtTail(head,2);
    // head->insertAtTail(head,3);
    // head->insertAtTail(head,4);
    // head->insertAtTail(head,5);
    // head->insertAtTail(head,6);
    // head->insertAtTail(head,7);
    // head->insertAtTail(head,8);
    // head->insertAtTail(head,9);
    // head->insertAtTail(head,10);


    head->printLnkdLst(head);

    cout<<head->lengthOfLnkdLst(head)<<endl;

    Solution s;
    // s.splitListToParts(head,5)[0]->printLnkdLst(s.splitListToParts(head,5)[0]);
    vector<node*> v = s.splitListToParts(head,1);

    for(int i = 0 ; i < v.size() ; i++)
    {
        v[i]->printLnkdLst(v[i]);
    }
    return 0;
}
