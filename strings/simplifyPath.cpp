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
    queue<string> st;
    string tempString = "";

    for(int i = 0 ; i < path.length(); i++)
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
            i++;
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
                // st.pop();
                // if(st.size() == 1)
                // {
                //     continue;
                // }
                // else
                // {
                // }
                if(path[i-1] == '/' & st.size() != 1)
                {
                    st.pop();
                }
            }
            else
            {
                continue;
            }
            
        }
        else if(path[i] == '.')
        {
            
            if(tempString.length() > 0)
            {
                st.push(tempString);
                tempString = "";
            }
            i++;
            st.pop();
            continue;
        }
        else
        {
            tempString += path[i];
        }
    }    

   
    if(st.size() == 1)
    {
        res += st.front();
        st.pop();
        return res;
    }

    while(st.size() != 1)
    {
        res += st.front();
        st.pop();
    }

    st.pop(); //remove last '/' for canonical path format

    return res;
}

int main()
{
    string s = "/a/./b/../../c/";
    cout<<simplifyPath(s)<<endl;

    return 0;
}