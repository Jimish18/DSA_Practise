#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

    int numJewelsInStones(string jewels, string stones) 
    {
        int count = 0;
        for(int i = 0 ; i < jewels.size() ; i++)
        {
            for(int j = 0 ; j < stones.size() ; j++)
            {
                if(jewels[i] == stones[j])
                {
                    count++;
                }
            }

        }  

        return count;  
    }
};
int main()
{    
    string j = "z";
    string s = "ZZ";

    Solution sol;
    cout<<sol.numJewelsInStones(j,s)<<endl;
    

    return 0;
}