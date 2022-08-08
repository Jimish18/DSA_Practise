#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> nums,int k)
{
    vector<int> ans;

    while(nums.size() != k)
    {
        int windowMax = INT_MIN;
        for(int i = 0 ; i < k ; i++)
        {
            if(nums[i] > windowMax)
            {
                windowMax = nums[i];
            }
        }

        ans.push_back(windowMax);
        nums.erase(nums.begin());
    }

    int windowMax = INT_MIN;
    for(int i = 0 ; i < k ; i++)
    {
        if(nums[i] > windowMax)
        {
            windowMax = nums[i];
        }
    }

    ans.push_back(windowMax);

    return ans;
}

int main()
{
    vector<int> a = {3,4,9,1,-4,10};
    for(int i = 0 ; i < slidingWindowMaximum(a,3).size();i++)
    {
        cout<<slidingWindowMaximum(a,3)[i]<<" ";
    }
    cout<<endl;

    return 0;
}