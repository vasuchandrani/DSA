#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> board, int n, int k, int mid){
    int painterCount =1;
    int valueSum =0;

    for(int i=0;i<n;i++){
        if(valueSum + board[i] <= mid){
            valueSum += board[i];
        }
        else{
            painterCount++;
            if(painterCount>k || board[i]>mid){
                return false;
            }
            valueSum =board[i];
        }
    }
    return true;
}

int painters(vector<int> board, int n, int k){

    int s =0;
    int sum =0;
    for(int i=0;i<n;i++){
        sum +=board[i];
    }
    int e =sum;
    int ans =-1;
    int mid = s+(e-s)/2;
    
    while(s<=e){
        if(isPossible(board,n,k,mid)){
            ans =mid;
            e =mid-1;
        }
        else{
            s =mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}


int main(){
    int n,k;
    cout<<"enter number of painters: "<<endl;
    cin>>k;
    cout<<"enter number of boards: "<<endl;
    cin>>n;
    cout<<"enter value of boards: "<<endl;

    vector<int> board;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        board.push_back(ele);
    }

    int ans =painters(board,n,k);
    cout<<ans<<endl;
    return 0;
}