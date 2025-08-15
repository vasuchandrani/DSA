#include<iostream>
#include<vector>
using namespace std;

class solution{
public:
    bool check(vector<int> &nums){

        int count = 0;
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1] > nums[i]){
                count++;
            }
        }
        if(nums[n-1] > nums[0]){
            count++;
        }
        return count<=1;
    }
};

int main(){
    solution s1;

    int n;
    cout<<"size: ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }

    int ans = s1.check(nums);
    cout<<ans;
}