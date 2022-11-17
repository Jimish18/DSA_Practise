/*
Question - Rectangle Area

Link - https://leetcode.com/problems/rectangle-area/
*/

#include <bits/stdc++.h>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
{
    int left = max(ax1,bx1);
    int right = max(min(ax2,bx2),left);

    int bottom = max(ay1,by1);
    int top = max(min(ay2,by2),bottom);

    return (ax2-ax1)*(ay2-ay1) - (right-left)*(top-bottom) + (bx2-bx1)*(by2-by1);
}

int main()
{
    return 0;
}