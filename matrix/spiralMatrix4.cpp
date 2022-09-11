/*
Question - Spiral matrix IV

Link - https://leetcode.com/problems/spiral-matrix-iv/
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;
};

void insertAtHead(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode* &head,int val)
{
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = NULL;
    ListNode* temp = head;

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

void printLnkdLst(ListNode* head)
{
    ListNode* temp = head;

    while(temp != NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
{
    vector<int> v(n,0);
    vector<vector<int>> matrix(m,v);

    int columnStart = 0;
    int columnEnd = n-1;
    int rowStart = 0;
    int rowEnd = m-1;

    ListNode* temp = head;

    while(rowStart <= rowEnd && columnStart <= columnEnd)
    {
        // for row Start
        for(int col = columnStart ; col <= columnEnd; col++)
        {
            if(temp != NULL)
            {
                matrix[rowStart][col] = temp->val;
                temp = temp->next;
            }
            else
            {
                matrix[rowStart][col] = -1;
            }

            // cout<<matrix[rowStart][col]<<" ";
        }
        // cout<<endl;
        if(++rowStart > rowEnd)
        {
            break;
        }

        // for column end
        for(int row = rowStart; row <= rowEnd; row++)
        {
            if(temp != NULL)
            {
                matrix[row][columnEnd] = temp->val;
                temp = temp->next;
            }
            else
            {
                matrix[row][columnEnd] = -1;
            } 

            // cout<<matrix[row][columnEnd]<<" ";

        }
        // cout<<endl;
        if(--columnEnd < columnStart)
        {
            break;
        }

        // for row end
        for(int col = columnEnd; col >= columnStart; col--)
        {
            if(temp != NULL)
            {
                matrix[rowEnd][col] = temp->val;
                temp = temp->next;
            }
            else
            {
                matrix[rowEnd][col] = -1;
            } 

            // cout<<matrix[rowEnd][col]<<" ";
        }
        // cout<<endl;
        if(--rowEnd < rowStart)
        {
            break;
        }

        // for column start
        for(int row = rowEnd; row >= rowStart; row--)
        {
            if(temp != NULL)
            {
                matrix[row][columnStart] = temp->val;
                temp = temp->next;
            }
            else
            {
                matrix[row][columnStart] = -1;
            } 

            // cout<<matrix[row][columnStart]<<" ";
        }
        // cout<<endl;
        if(columnStart++ > columnEnd)
        {
            break;
        }


    }

    return matrix;
}

int main()
{
    ListNode* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);

    printLnkdLst(head);

    vector<vector<int>> matrix = spiralMatrix(3,5,head);

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }    
        cout<<endl;

    }
    return 0;
}