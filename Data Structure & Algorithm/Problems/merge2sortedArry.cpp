#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v1,vector<int> &v2,vector<int> &v3){
    int n = v1.size();
    int m = v2.size();
    int i = 0;
    int j = 0;

    while(i<n && j<m){
        if(v1[i]<v2[j]){
            v3.push_back(v1[i]);
            i++;
        }
        else{
            v3.push_back(v2[j]);
            j++;
        }
    }
    while(i<n){
        v3.push_back(v1[i]);
        i++;
    }
    while(j<n){
        v3.push_back(v2[j]);
        j++;
    }
    for(int i=0;i<(n+m);i++){
        cout<<v3[i]<<" ";   
    }
}

int main(){
    int n,m;
    cout<<"first array size: ";
    cin>>n;
    cout<<"enter first sorted arry:"<<endl;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v1.push_back(ele);
    }
    cout<<"second array size: ";
    cin>>m;
    cout<<"enter second sorted arry:"<<endl;
    vector<int> v2;
    for(int i=0;i<m;i++){
        int ele;
        cin>>ele;
        v2.push_back(ele);
    }    

    vector<int> v3(n+m,0);  // size, initial value of all element
    merge(v1,v2,v3);

    return 0;
}