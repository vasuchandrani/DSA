//square root by binary search

#include<iostream>
using namespace std;

int integerSquareRoot(int n){
    int start =0;
    int end =n-1;
    int mid = start + (end-start)/2;

    while(start<=end){

        if(mid*mid==n){
            return mid;
        }
        if(mid*mid>n){
            end = mid-1;
        }
        if(mid*mid<n){
            start = mid+1;
        }

        mid = start + (end-start)/2;        
    }

    return -1;
}

double floatSqareRoot(int n, int integerAns, int precision){
    double factor = 1;
    double ans = integerAns;

    for(int i=0;i<precision;i++){
        factor = factor / 10;
        for(double j=ans;j*j<n;j +=factor){
            ans =j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter Square"<<endl;
    cin>>n;
    
    int integerAns = integerSquareRoot(n);
    if(integerAns>=0){
        cout<<"Integer Square-root is "<<integerAns<<endl;
    }
    else{
        cout<<"It is not perfect square"<<endl;
    }
    int precision;
    cout<<"Enter precision"<<endl;
    cin>>precision;
    double floatAns = floatSqareRoot(n,integerAns,precision);

    cout<<"Float Square-root is "<<floatAns<<endl;
}