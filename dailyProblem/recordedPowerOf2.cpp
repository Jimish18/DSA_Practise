/*
Question - Recorded Power of 2

You are given an integer n. We reorder the digits in any order (including the original order) such 
that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
 

Constraints:

1 <= n <= 109
*/

#include <bits/stdc++.h>
using namespace std;

bool reorderedPowerOf2(int n) 
{
    string number = to_string(n);
    bool flag = false;

    sort(number.begin(),number.end());
    // vector<string> v(31);
    string s;

    for(int i = 0;i <= 10; i++){
        int powerOf2 = pow(2,i);
        s = to_string(powerOf2);
        sort(s.begin(), s.end());
        if(s == number)
        {
            flag = true;
            return flag;
        }
        // v.push_back(s);        
    }  


    return flag;
}

int main()
{
    cout<<reorderedPowerOf2(1024)<<endl;

    return 0;
}