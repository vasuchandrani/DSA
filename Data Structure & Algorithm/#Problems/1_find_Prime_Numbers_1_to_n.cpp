#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

// Sieve of Eratosthenes Approach

class Prime {   // T.C. = O(n * log(log n))

    long long countPrime(int n) {

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i=2; i*i <= n; i++) {

            if (isPrime[i]) {

                for (int j=i*i; j<=n; j++) { // if we start j = i+i; T.C. = O(n * log(n))
                    isPrime[j] = false;
                }
            }
        }
        
        long long cnt = 0;
        // printing and counting prime numbers
        for (int i=0; i<n; i++) {
            if (isPrime[i] == true) {
                // cout<<i<<" ";
                cnt++;
            }
        } 
        // cout<<endl;
        
        // return total prime numbers
        return cnt;
    }   
};