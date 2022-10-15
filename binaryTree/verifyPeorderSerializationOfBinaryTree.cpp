/*
Question - verify serialization of binary tree

Link - https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

// bool isValidSerialization(string preorder) 
// {
//     stack<string> st;
//     vector<string> v ;
//     string temp = "";

//     for(int i = 0 ; i < preorder.size(); i++)
//     {
//         if(preorder[i] == ',')
//         {
//             v.push_back(temp);
//             temp = "";
//         }   
//         else
//         {
//             temp += preorder[i];
//         }

//         if(i == preorder.size()-1)
//         {
//             v.push_back(temp);
//         }
//     }  

//     for(string x : v)
//     {
//         if(x == "#")
//         {
//             while(st.size() >= 2 && st.top() == "#")
//             {
//                 st.pop();
//                 if(st.top() != "#") st.pop();
//             }
//         }
//         st.push(x);
//     }   

//     return (st.size()==1 && st.top()== "#");
// }

bool isValidSerialization(string preorder) 
{
    vector<string> v ;
    string temp = "";

    for(int i = 0 ; i < preorder.size(); i++)
    {
        if(preorder[i] == ',')
        {
            v.push_back(temp);
            temp = "";
        }   
        else
        {
            temp += preorder[i];
        }

        if(i == preorder.size()-1)
        {
            v.push_back(temp);
        }
    }  

    int diff = 1;

    for(string x : v)
    {
        if(--diff < 0) return false;
        if(x != "#") diff += 2;
    } 

    return (diff == 0);
}

int main()
{
    string preorder = "9,#,92,#,#";
    // 1,#
    // 9,3,4,#,#,1,#,#,2,#,6,#,#
    // 9,#,#,1
    // 9,#,92,#,#
    cout<<isValidSerialization(preorder)<<endl;

    return 0;
}