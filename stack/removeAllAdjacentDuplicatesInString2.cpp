/*
Question - Remove All Adjacent Duplicates in String II

Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

#include <bits/stdc++.h>
using namespace std;

// string removeDuplicates(string s, int k) 
// {
//     stack<pair<char,int>> st;
//     int n = s.length();

//     for(int i = 0; i < n; i++)
//     {
//         if(!st.empty())
//         {
//             if(s[i] == st.top().first)
//             {
//                 st.push({s[i],st.top().second+1});

//                 if(st.top().second >= k)
//                 {
//                     int count = k;
//                     while(!st.empty() && count--)
//                     {
//                         st.pop();
//                     }
//                 }               
                
//             }
//             else
//             {
//                 st.push({s[i],1});
//             }

//         }
//         else
//         {
//             st.push({s[i],1});
//         }
//     } 

//     string ans = "";

//     while(!st.empty())
//     {
//         ans.insert(ans.begin(),st.top().first);
//         st.pop();
//     }       

//     return ans;
// }

string removeDuplicates(string s, int k) 
{
    stack<pair<char,int>> st;
    int n = s.length();

    for(int i = 0; i < n; i++)
    {
        if(!st.empty())
        {
            if(s[i] == st.top().first)
            {
                st.top().second++;

                if(st.top().second >= k)
                {
                    st.pop();
                }               
                
            }
            else
            {
                st.push({s[i],1});
            }

        }
        else
        {
            st.push({s[i],1});
        }
    } 

    string ans = "";

    while(!st.empty())
    {
        for(int i = 0; i < st.top().second; i++) ans.insert(ans.begin(),st.top().first);
        st.pop();
    }       

    return ans;
}

int main()
{
    return 0;
}