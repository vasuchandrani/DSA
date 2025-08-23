#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// Make the array palindromic by adding adjacent elements.
// You are allowed to merge two adjacent elements into their sum.
// Find the minimum number of such merge operations required to make the array a palindrome.

class Palindrom {

    int countOperation (vector<int>& arr) {

        int n = arr.size();
        int l = 0;
        int r = n-1;
        int opr = 0;

        while (l < r) {

            if (arr[l] == arr[r]) {
                l++;
                r--;
            }
            else if (arr[l] < arr[r]) {
                arr[l+1] += arr[l];
                l++;
                opr++;
            }
            else {
                arr[r-1] += arr[r];
                r--;
                opr++;
            }
        }

        return opr;
    }
};