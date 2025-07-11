// 26/9/2024
// link = https://leetcode.com/problems/my-calendar-i/?envType=daily-question&envId=2024-09-26

#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // find the first event that starts after or st the same time of {start, end}
        auto it = st.lower_bound({start, end}); //Log(N)

        //Check if overlaps with the next event
        if (it != st.end() && it->first < end) {
            return false;
        }

        //Check if overlaps with the previous event
        if (it != st.begin()) {
            auto prevIt = prev(it);
            if (start < prevIt->second) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */