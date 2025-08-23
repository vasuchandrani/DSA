#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &v){
    int s = 0;
    int e = v.size()-1;
    
    while(s <= e){
        swap(v[s], v[e]);
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

    reverse(v);

    cout<<"Reversed array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}