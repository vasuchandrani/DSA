//22/8/2024

#include<bits/stdc++.h>
using namespace std;

// code-1
class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1;

        for (int i=0; i<numBits; i++) {
            num = num ^ (1 << i);
        }

        return num;
    }
};


// code-2
class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1;

        unsigned int mask = (1U << numBits) - 1;

        return (num ^ mask);
    }
};


// code-3
class Solution {
public:
    int findComplement(int num) {

        int i = 0;
        int compliment = 0;

        while (num) {
            if (!(num&1)) {
                compliment |= (1 << i);
            }

            num >>= 1;
            i++;
        }

        return compliment;
    }
};