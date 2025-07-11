// 23/08/2024
// link - https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23

#include<iostream>
using namespace std;

class Solution {
public:
    string fractionAddition(string expr) {
        
        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = expr.length();
        while (i < n) {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');

            if (expr[i] == '+' || expr[i] == '-') {
                i++;
            } 

            // Make currNume 
            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }
            i++; //skiping the divisor char '/'

            if (isNeg) {
                currNume *= -1;
            }

            // Make currDeno
            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++; 
            }

            nume = currNume * deno + currDeno * nume;
            deno = deno * currDeno;
        }

        // int GCD = abs(__gcd(nume, deno));   

        // nume /= GCD;
        // deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};
