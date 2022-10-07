/*
Question - Smallest String Starting From Leaf

Link - https://leetcode.com/problems/smallest-string-starting-from-leaf/
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// void dfs(TreeNode* root,string &result,string &temp,bool &check)
// {
//     if(!root)
//     {
//         return ;
//     }

//     if(!root->left && !root->right)
//     {
//         if(check)
//         {
//             if(temp < result)
//             {
//                 result = temp;
//             }
//         }
//         else
//         {

//         }
//     }


// }

string answer = "~";

void recure(TreeNode* root,string s){
            if (!root) return;
            if (!root->left && !root->right){
                answer = min(answer,char(root->val+'a')+s);
            }
            recure(root->left,char(root->val+'a')+s);
            recure(root->right,char(root->val+'a')+s);
}
    string smallestFromLeaf(TreeNode* root) {
        recure(root,"");
        return answer;
    }

string smallestFromLeaf(TreeNode* root) 
{

}

int main()
{
    // vector<string> s = {"John","Remo","Mixy","Julie","Ronny"};

    // cout<<"before Sorting =>"<<endl;
    // for(int i = 0 ; i < s.size(); i++)
    // {
    //     cout<<s[i]<<endl;
    // }

    // cout<<"After Sorting =>"<<endl;
    // sort(s.begin(),s.end());
    // for(int i = 0 ; i < s.size(); i++)
    // {
    //     cout<<s[i]<<endl;
    // }

    // cout<<(s[0]<s[1])<<endl;

    cout<<(char)(1+'a')<<endl;
    return 0;
}