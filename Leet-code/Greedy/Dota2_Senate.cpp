// 649

#include<bits/stdc++.h>
using namespace std;

// Brute-Force 
class Solution {
public:

    bool removeSenate(string &senate, char ch, int idx) {

        bool checkRemovalLeftSide = false;

        while (true) {

            if (idx == 0) {
                checkRemovalLeftSide = true;
            }

            if (senate[idx] == ch) {
                senate.erase(begin(senate) + idx);  //shift
                break;
            }

            idx = (idx+1) % (senate.length());
        }

        return checkRemovalLeftSide;
    }

    string predictPartyVictory(string senate) {
        
        int R_count = count(senate.begin(), senate.end(), 'R');
        int D_count = senate.length() - R_count;

        int idx = 0;

        while (R_count > 0 && D_count > 0) {

            if (senate[idx] == 'R') {

                bool checkRemovalLeftSide = removeSenate(senate, 'D', (idx+1)%(senate.length()));
                D_count--;
                if(checkRemovalLeftSide) {
                    idx--;
                }
            } else {

                bool checkRemovalLeftSide = removeSenate(senate, 'R', (idx+1)%(senate.length()));
                R_count--;
                if(checkRemovalLeftSide) {
                    idx--;
                }
            }

            idx = (idx+1) % (senate.length());
        }

        return R_count == 0 ? "Dire" : "Radient";
    }
};


class Solution {
public:
    int  n;
    void removeSenate(string &senate, vector<bool> &removed, char ch, int idx) {

        while (true) {

            if (senate[idx] == ch && removed[idx] == false) {
                removed[idx] = true;   
                break;
            }

            idx = (idx+1) % n;
        }

    }

    string predictPartyVictory(string senate) {
        
        n = senate.length();

        int R_count = count(senate.begin(), senate.end(), 'R');
        int D_count = n - R_count;
        vector<bool> removed(n, false);

        int idx = 0;

        while (R_count > 0 && D_count > 0) {

            if (removed[idx] == false) {

                if (senate[idx] == 'R') {

                    removeSenate(senate, removed, 'D', (idx+1)%n);
                    D_count--;
                    
                } else {

                    removeSenate(senate, removed, 'R', (idx+1)%n);
                    R_count--;
    
                }
            }

            idx = (idx+1) % n;
        }

        return R_count == 0 ? "Dire" : "Radiant";
    }
};

