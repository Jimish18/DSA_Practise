/*
Question - Fraction to Reccuring Decimal

Link - https://leetcode.com/problems/fraction-to-recurring-decimal/
*/

#include <bits/stdc++.h>
using namespace std;

string toString(long long n)
{
    if(n == 0) return "0";

    string ans = "";

    while(n > 0)
    {
        string dem = "";
        dem += ((n%10) + '0');

        ans = dem + ans;
        n /=10;
    }

    return ans;
}

string fractionToDecimal(int numerator, int denominator) 
{
    if(numerator == 0) return "0";

    string ans = "";

    if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) ans.push_back('-');
    numerator = abs(numerator);
    denominator = abs(denominator);

    long long quotient = numerator / denominator;
    long long reminder = numerator % denominator;

    ans = ans + toString(quotient);
    if(reminder == 0) return ans;
    else
    {
        ans += '.';
        unordered_map<long long,int> umap;

        while(reminder != 0)
        {
            if(umap.find(reminder) != umap.end())
            {
                int pos = umap[reminder];
                ans.insert(ans.begin()+pos,'(');
                ans += ')';
                break;
            }
            else
            {
                umap[reminder] = ans.length();
                reminder *= 10;
                quotient = reminder/denominator;
                reminder = reminder%denominator;
                ans += toString(quotient);
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}