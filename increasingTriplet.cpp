class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n<3) return false;
        
        int a = INT_MAX;
        int b = INT_MAX;
        
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>b) return true;
            
            // update b or set b;
           else if(nums[i]>a) b= nums[i];
            else if(nums[i]<a) a = nums[i];
            
        }
        
        return false;
        
        
    }
};
