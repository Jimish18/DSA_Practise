/*
Question - Final Prices With a Special Discount in a Shop
Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.

 

Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. 
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2. 
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4. 
For items 3 and 4 you will not receive any discount at all.

Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.

Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) 
{
    stack<int> st;
    vector<int> result;

    st.push(prices[prices.size()-1]);
    result.push_back(prices[prices.size()-1]);

    for(int  i = prices.size()-2 ; i >= 0 ; i--)
    {
        if(prices[i] <= st.top())
        {
            while(!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }

            
            if(st.empty())
            {
                result.push_back(prices[i]);
                st.push(prices[i]);
            }
            else
            {
                result.push_back(prices[i]-st.top());
                st.push(prices[i]);
            }
        }

        if(prices[i] > st.top())
        {
            result.push_back(prices[i]-st.top());
            st.push(prices[i]);
        }
    }       
    vector<int> finalResultArray;

    for(int i = result.size()-1 ; i >= 0 ; i--)
    {
        finalResultArray.push_back(result[i]);
        result.pop_back();
    }

    return finalResultArray;

}

int main()
{
    vector<int> v = {10,1,1,6};

    for(int i = 0 ; i < finalPrices(v).size(); i++)
    {
        cout<<finalPrices(v)[i]<<" ";
    }
    // finalPrices(v);

    return 0;
}