#include<iostream>
#include<vector>
using namespace std;

// if you use push back then you need to reverse the array by below function 
// void reverse(vector<int> v){
//     int s = 0;
//     int e = v.size()-1;

//     while(s<e){
//         swap(v[s++], v[e--]);
//     }
    
//     int size = v.size();
//     for(int i=0;i<size;i++){
//         cout<<v[i];
//     }
// }

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m){

    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;

    while(i>=0 && j>=0){
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum/10;
        sum = sum%10;
        ans.insert(ans.begin(),sum);
        i--;
        j--;
    }

    //first case
    while(i>0){
        
        int sum = a[i] + carry;

        carry = sum/10;
        sum = sum%10;
        ans.insert(ans.begin(),sum);
        i--;
    }

    //second case
    while(j>0){
        
        int sum = b[j] + carry;

        carry = sum/10;
        sum = sum%10;
        ans.insert(ans.begin(),sum);
        j--;
    }

    //third case
    while(carry != 0){
        
        int sum = carry;

        carry = sum/10;
        sum = sum%10;
        ans.insert(ans.begin(),sum);
    }

    return ans;
}

int main(){
    int n,m;
    cout<<"size of first: ";
    cin>>n;
    cout<<"size of second: ";
    cin>>m;

    cout<<"enter first arry"<<endl;
    vector<int> a;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        a.push_back(ele);
    }

    cout<<"enter second arry"<<endl;
    vector<int> b;
    for(int i=0;i<m;i++){
        int ele;
        cin>>ele;
        b.push_back(ele);
    }

    vector<int> ans = findArraySum(a,n,b,m);

    int size = ans.size();
    for(int i=0;i<size;i++){
        cout<<ans[i];
    }

}