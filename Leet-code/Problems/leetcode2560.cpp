class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            
            int n = nums.size();
    
            vector<int> minAtLeft(n);
    
            int mini = nums[n-1];
            for (int i=n-3; i>=0; i--) {
                minAtLeft[i] = mini;
    
                mini = min(mini, nums[i+1]);
            }
    
            int capability = INT_MAX;
            for (int i=0; i<n-3; i++) {
                
                int temp = max(nums[i], minAtLeft[i]);
    
                capability = min(capability, temp);
            }
    
            return capability;
        }
    };