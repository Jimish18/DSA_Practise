/*
Question - Capacity To Ship Packages Within D Days

Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

#include <bits/stdc++.h>
using namespace std;


bool partition_possible(vector<int>& weights,int max_weight,int days){
    int count = 1;
    int sum = weights[0];
    for(int i=1;i<weights.size();i++){
        if(sum + weights[i] <= max_weight){
            sum += weights[i];
        }
        else{
            count++;
            sum = weights[i];
        }
    }
    if(count <= days){
            return true;
    }
    return false;
}
int binarySearch(vector<int>& weights, int days,int start,int end){
    int mid = start + (end - start)/2;
    int result = 0;
    while(start <= end){
        mid = start + (end - start)/2;
        bool check = partition_possible(weights,mid,days);
        
        if(check){
            end = mid-1; 
            result = mid;
        }
        else{
            start = mid+1;
        }
    }
    return result;

}
int shipWithinDays(vector<int>& weights, int days) {
    int maximum_element = 0;
    int max_range = 0;
    for(int i=0;i<weights.size();i++){
        max_range += weights[i];
        maximum_element = max(maximum_element,weights[i]);
    }
    return binarySearch(weights,days,maximum_element,max_range);
}
int main()
{
    return 0;
}