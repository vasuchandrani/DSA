// 27/9/2024
// link = https://leetcode.com/problems/my-calendar-ii/?envType=daily-question&envId=2024-09-27

#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverLappedRegion;
    vector<pair<int, int>> OverAllBooking;

    MyCalendarTwo() {
        
    }

    bool checkOverlap (int a1, int b1, int a2, int b2) {
        return max(a1, a2) < min(b1, b2);
    }

    pair<int, int> findOverlappedRegion(int a1, int b1, int a2, int b2) {
        return {max(a1, a2), min(b1, b2)};
    }
    
    bool book(int start, int end) {
        
        // check if triple booking is being created or not?
        for (pair<int, int> region : doubleOverLappedRegion) {
            if (checkOverlap(region.first, region.second, start, end)) {
                return false;
            }
        }

        // check if double booking is being created for update doubleOverlappedRegion;
        for (pair<int, int> booking : OverAllBooking) {
            if (checkOverlap(booking.first, booking.second, start, end)) {
                doubleOverLappedRegion.push_back(findOverlappedRegion(booking.first, booking.second, start, end)); 
            }
        }

        OverAllBooking.push_back({start, end});
        return true;
    }
};
 
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
**/