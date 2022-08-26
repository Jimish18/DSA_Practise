/*
Question - simplify path

Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

 

Example 1:
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:
Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/

#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) 
{
    string res = "";
    stack<string> st;
    string tempString = "";

    int i = 0;
    while(i < path.length())
    {
        if(path[i] == '/' && path[i+1] == '/')
        {
            if(tempString.length() > 0)
            {
                st.push(tempString);
                tempString = "";
            }
            tempString += path[i];
            st.push(tempString);
            tempString = "";
            i++;i++;
            continue;
        }
        else if(path[i] == '/')
        {
            if(tempString.length() > 0)
            {
                st.push(tempString);
                tempString = "";
            }
            tempString += path[i];
            st.push(tempString);
            tempString = "";
            
        }
        else if(path[i] == '.' && path[i+1]== '.')
        {
            if(tempString.length() > 0)
            {
                st.push(tempString);
                tempString = "";
            }

            if(st.size() > 1)
            {
                st.pop();
                st.pop();
            }
            // else
            // {
            //     continue;
            // }
            i++;i++;i++;
            continue;
            
        }
        else if(path[i] == '.' && path[i+1] == '/')
        {
            
            if(tempString.length() > 0)
            {
                st.push(tempString);
                tempString = "";
            }
            st.pop();
        }
        else
        {
            tempString += path[i];
        }
        i++;
    }    

    // cout<<st.size()<<endl;

   
    if(st.size() == 1)
    {
        res += st.top();
        st.pop();
        return res;
    }

    stack<string> reverseStack;

    while(!st.empty())
    {
        reverseStack.push(st.top());
        st.pop();
    }

    while(reverseStack.size() != 1)
    {
        res += reverseStack.top();
        reverseStack.pop();
    }

    // st.pop(); //remove last '/' for canonical path format

    return res;
}

int main()
{
    string s = "/a/./b/../../c//.//";
    cout<<simplifyPath(s)<<endl;
    // simplifyPath(s);

    return 0;
}