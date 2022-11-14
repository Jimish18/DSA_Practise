/*
Question - Seat Reservation Manager

Link - https://leetcode.com/problems/seat-reservation-manager/
*/

#include <bits/stdc++.h>
using namespace std;

class SeatManager {
public:

priority_queue<int,vector<int>,greater<int>> minH;
SeatManager(int n) {
    for(int i = 1; i <= n; i++)
    {
        minH.push(i);
    }
}

int reserve() 
{
    int seatNumber = minH.top();
    minH.pop();
    return seatNumber;
}

void unreserve(int seatNumber) 
{
    minH.push(seatNumber)        ;
}

};

int main()
{
    return 0;
}