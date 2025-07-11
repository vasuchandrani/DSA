#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool IsNonSpecial(int i){
        
        int count = 0;
        int j = 1;
        cout<<"in fn "<<i<<endl;
            
        while(j<i){
            if(i%j==0){
                j++;
                count++;
            }
            else{
                j++;
            }
            if(count>2){
                return true;
            }
        }
        if(count<2)
            return true;
        else
            return false;
    }

    int nonSpecialCount(int l, int r) {
        int count = 0;
        
        for(int i=l;i<=r;i++){
            if(IsNonSpecial(i)){
                cout<<"I= "<<i<<endl;
                count++;
            }
        }
        return count;
    }
}S; 

int main(){

    int ans = S.nonSpecialCount(4, 16);
    cout<<ans<<endl;
}