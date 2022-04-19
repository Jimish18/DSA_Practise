/*
Problem Statement :-> 
    You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

    Given the string command, return the Goal Parser's interpretation of command.

Example1:
Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example2:
Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:
Input: command = "(al)G(al)()()G"
Output: "alGalooG"
*/


#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    string interpret(string command) 
    {
        string res = "";
        int count;

        for(int i = 0 ; i < command.length(); i++)
        {
            count = 0;

            if(command[i] == '(')
            {
                while(command[i] != ')')
                {
                    count++;
                    i++;
                }

                if(count == 1)
                {
                    res += "o";
                }
                if(count == 3)
                {
                    res += "al";
                }
            }
            else
            {
                res += command[i];
            }
        }

        return res;
    }
};

int main()
{
    string s = "(al)G(al)()()G";
    // "G()(al)"
    // "G()()()()(al)"
    Solution sol;
    cout<<sol.interpret(s)<<endl;

    return 0;
}