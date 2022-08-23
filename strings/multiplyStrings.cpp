/*
Question - Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <bits/stdc++.h>
using namespace std;

unsigned long int stringIntoInt(string n)
{
    long long decimal = 0;
    unsigned long int number = 0;

    for(int i = n.length()-1 ; i >= 0; i--)
    {
        number += (n[i]-'0')*(pow(10,decimal));
        decimal++;
    }

    return number;
}

string multiply(string num1, string num2) 
{
    unsigned long int number = (stringIntoInt(num1))*(stringIntoInt(num2));
    long long i = 0;
    string finalNumber = "";

    if(number == 0)
    {
        return "0";
    }

    while(number != 0)
    {
        i = number%10;
        finalNumber.insert(0,1,i+'0');
        number = number/10;
    }

    return finalNumber;
}

int main()
{ 
    cout<<multiply("0","0")<<endl;
    
    return 0;
}