//Largest distance between aggrasive cows

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k,int mid){
    
    int cowCount =1;
    int firstPos =stalls[0];
    
    int size =stalls.size();
    for(int i=0;i<size;i++){
        if(stalls[i] - firstPos >= mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            firstPos =stalls[i];
        }
    }
    return false;
}

int cows(vector<int> &stalls, int k){

    int s =0;
    int maxi =-1;

    int size =stalls.size();
    for(int i=0;i<size;i++){
        maxi = max(maxi,stalls[i]);
    }
    int e =maxi;
    int mid = s+(e-s)/2;
    int ans =-1;

    while(s<=e){
        if(isPossible(stalls, k, mid)){
            ans =mid;
            s =mid+1;
        }
        else{
            e =mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    int n,k;
    cout<<"enter number of cows: "<<endl;
    cin>>k;
    cout<<"enter number of stalls: "<<endl;
    cin>>n;
    cout<<"enter cordinates of stalls: "<<endl;
    vector<int> stalls;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        stalls.push_back(ele);
    }
    //sort(stalls.begin(), stalls.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(stalls[i]>stalls[j]){
                swap(stalls[i],stalls[j]);
            }
        }
    }

    int ans = cows(stalls,k);
    cout<<ans<<endl;

    return 0;
}