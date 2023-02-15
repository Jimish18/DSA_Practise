/*
Question - Add to Array-Form of Integer

Link - https://leetcode.com/problems/add-to-array-form-of-integer/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) 
{
    int n = num.size();
    string temp = to_string(k);
    int carry = 0;
    int m = temp.length();
    int j = m-1;
    int i = n-1;


    if(i>j)
    {
        while(j >= 0)
        {            
            int tempNum = num[i] + (temp[j]-'0') + carry;
            num[i] = tempNum%10;
            carry = tempNum / 10;
            j--;
            i--;
        }

        while(carry || i >= 0)
        {
            if(i >= 0)
            {
                int tempNum = num[i] + carry;
                num[i] = tempNum%10;
                carry = tempNum/10;
                i--;
            }
            else
            {
                num.insert(num.begin(),carry);
                carry = carry/10;
            }
        }

       
    }
    else
    {
        while(i >= 0)
        {            
            int tempNum = num[i] + (temp[j]-'0') + carry;
            num[i] = tempNum%10;
            carry = tempNum/10;
            j--;
            i--;
        }        

        while(j >= 0 || carry)
        {
            if(j >= 0)
            {
                int tempNum = (temp[j]-'0')+carry;
                num.insert(num.begin(),tempNum%10);
                carry = tempNum/10;
                j--;
            }
            else
            {
                num.insert(num.begin(),carry);  
                carry = carry/10;
            }
        }
    }

    return num;
           
}
int main()
{
    return 0;
}