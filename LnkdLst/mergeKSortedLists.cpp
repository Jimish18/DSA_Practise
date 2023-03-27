/*
Question - Merge K Sorted Lists

Link - https://leetcode.com/problems/merge-k-sorted-lists/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// (Divide and conquer) & (merge Sort) method 
// ListNode* mergeLists(ListNode* &head1 ,ListNode* &head2)
// {
//     ListNode* dummy = new ListNode();
//     ListNode* temp = dummy;

//     while(head1 && head2)
//     {
//         if(head1->val < head2->val)
//         {
//             temp->next = head1;
//             head1 = head1->next;
//         }
//         else
//         {
//             temp->next = head2;
//             head2 = head2->next;
//         }

//         temp = temp->next;
//     }

//     temp->next = head1 ? head1 : head2;

//     return dummy->next;
// }

// ListNode* mergeKSortedListsHelper(vector<ListNode*>& lists,int start,int end)
// {
//     if(start == end) return lists[start];

//     if(start+1 == end) return mergeLists(lists[start],lists[end]);

//     int mid = start + (end - start)/2;

//     ListNode* left = mergeKSortedListsHelper(lists,start,mid);
//     ListNode* right = mergeKSortedListsHelper(lists,mid+1,end);

//     return mergeLists(left,right);
// }

// ListNode* mergeKLists(vector<ListNode*>& lists) 
// {
//     if(lists.size() == 0) return NULL;

//     return mergeKSortedListsHelper(lists,0,lists.size()-1);
// }

// Heap Method
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.size() == 0) return NULL;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
    
    for(int i = 0 ; i < lists.size(); i++)
    {
        if(lists[i]) minH.push({lists[i]->val,i});
    }

    if(minH.empty()) return NULL;

    ListNode* node = new ListNode();
    ListNode* head = node;

    while(true)
    {
        pair<int,int> temp = minH.top();
        minH.pop();
        
        node->val = temp.first;

        if(lists[temp.second]->next)
        {
            lists[temp.second] = lists[temp.second]->next;
            minH.push({lists[temp.second]->val,temp.second});
        }

        if(!minH.empty())
        {
            node->next = new ListNode();
            node = node->next;
        }
        else
        {
            break;
        }
    }

    return head;
}      

int main()
{
    return 0;
}