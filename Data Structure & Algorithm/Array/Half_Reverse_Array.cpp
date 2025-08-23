#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &v, int m){
    int s=m;
    int e=v.size()-1;
    
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;    
    }
}

int main(){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    
    cout<<"enter array"<<endl;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"From which index do u want to reverse??"<<endl;
    int m;
    cin>>m;
    reverse(v,m);

    cout<<"Reversed array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}