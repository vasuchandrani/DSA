#include<iostream>
#include<vector>
using namespace std;
 
class solution{
public:
    void rotate(vector<int> &nums, int k){
 
        vector<int> temp(nums.size());  //define for avoid over write problem
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp[(i+k)%nums.size()] = nums[i];
        }
        //copy temp into num vector
        nums = temp;
    }
};
 
int main(){
 
    solution s1;
 
    int k,n;
    cout<<"size: ";
    cin>>n;
    cout<<"rotate no.: ";
    cin>>k;
    cout<<"enter array: ";
    vector<int> nums;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
 
    s1.rotate(nums,k);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
 
}