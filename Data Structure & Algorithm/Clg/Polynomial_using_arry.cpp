#include<iostream>
using namespace std;

struct Poly {
    int coeff;
    int expo;
};

void add (Poly poly1[], Poly poly2[], Poly poly3[], int a, int b) {

    int i = 0, j = 0;
    int k = 0;
    while (i<a && j<b) {

        if (poly1[i].expo == poly2[j].expo) {
            poly3[k].expo = poly1[i].expo;
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if (poly1[i].expo < poly2[j].expo) {
            poly3[k].expo = poly1[i].expo;
            poly3[k].coeff = poly1[i].coeff;
            i++;
            k++;
        }
        else {
            poly3[k].expo = poly2[j].expo;
            poly3[k].coeff = poly2[j].coeff;
            j++;
            k++;
        }
    }
}

int main () {

    int a, b;
    cout<<"Enter terms of 1st poly"<<endl;
    cin>>a;
    cout<<"Enter terms of 2nd poly"<<endl;
    cin>>b;

    Poly poly1[a], poly2[b];
    int n = (a > b) ? a : b;
    Poly poly3[n];

    cout<<"Enter 1st polinomial"<<endl;
    for (int i=0; i<a; i++) {
        cout<<"coeff-> ";    cin>>poly1[i].coeff;
        cout<<"expo-> ";     cin>>poly1[i].expo;
    }

    cout<<"Enter 2st polinomial"<<endl;
    for (int i=0; i<b; i++) {
        cout<<"coeff-> ";    cin>>poly2[i].coeff;
        cout<<"expo-> ";     cin>>poly2[i].expo;
    }

    add(poly1, poly2, poly3, a, b);
    
    for (int i=0; i<n; i++) {
        if (i == n-1){
            cout<<poly3[i].coeff<<"X^"<<poly3[i].expo;
        } else {
            cout<<poly3[i].coeff<<"X^"<<poly3[i].expo<<" + ";
        }
    }

    return 0;
}