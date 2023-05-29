/*
Question - Design Parking System

link - https://leetcode.com/problems/design-parking-system/description/
*/

#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
public:
    int b;
    int m;
    int s;
    ParkingSystem(int big, int medium, int small) 
    {
        b=big;
        m=medium;
        s=small;  
    }
    
    bool addCar(int carType) 
    {
        if(carType == 1)
        {
            if(b > 0)
            {
                b--;
                return true;
            }
            else return false;
        }
        else if(carType == 2)
        {
            if(m > 0)
            {
                m--;
                return true;
            }
            else return false;
        }
        else
        {
            if(s > 0)
            {
                s--;
                return true;
            }
            else return false;
        }
    }
};