/*
Question - Flattening Linked List

Link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* mergeLinkedList(Node* a, Node* b)
{
    Node* temp = new Node(0);
    Node* newHead = temp;

    while(a && b)
    {
        if(a->data > b->data)
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
        else
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
    }

    if(a) temp->bottom = a;
    else temp->bottom = b;

    return newHead->bottom;
}

Node* flatten(Node *root)
{
    if(!root || !root->next) return root;

    root->next = flatten(root->next);

    root = mergeLinkedList(root, root->next);

    return root;
}
    

int main()
{
    return 0;
}