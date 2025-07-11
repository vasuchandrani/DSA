#include<bits/stdc++.h>
using namespace std;

int coins[4] = {1, 2, 5, 10};

int minCoins (int n) {

    int i = 3;
    int cnt = 0;
    while (n > 0) {
        
        if (n > coins[i]) {
            cnt += n/coins[i];
            n = n - cnt*coins[i];
        } else {
            i--;
        }
    }

    return cnt;
}

int main () {
    int n; 
    cout<<"Enter the value of rupee"<<endl;
    cin>>n;

    cout<<"no. of coins required"<<endl;
    int coins = minCoins(n);
    cout<<coins<<endl;
}
