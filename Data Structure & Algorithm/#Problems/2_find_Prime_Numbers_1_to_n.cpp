#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

// Linear Sieve (Euler’s Sieve) Approach

class Prime {   // T.C. = O(n)

    long long countPrime(int n) {

        vector<int> primes;
        vector<int> lp(n+1, 0); // lowest prime

        for (int i=2; i<=n; i++) {
            
            if (lp[i] == 0) {
                lp[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > lp[i] || i *p > n) 
                    break;
                
                lp[i *p] = p;
            }
        }

        long long cnt = primes.size();
        // printing and counting prime numbers
        for (long long p : primes) {
            cout<<p<<" ";
        }
        // cout<<endl;
        
        // return total prime numbers
        return cnt;
    }   
};