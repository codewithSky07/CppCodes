class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // if nums size is less than 2.
        if(nums.size()<2)
            return false;
        
        // declare map.
        unordered_map<int,int>mp;
        
    // initial index as -ve. case when first number is multiple of k.
        mp[0]=-1;
        
        int running_sum=0;
        
        for(int i=0;i<nums.size();i++){
            
            running_sum+=nums[i];
            
            //  to find out mod
            if(k!=0) running_sum%=k;
            
            // if mod found.
            if(mp.find(running_sum)!=mp.end()){
                // if subarray is having length more than or equal to 2.
                if(i-mp[running_sum]>1) return true;
            }
            else{
                // if not present store the (mod, index).
                mp[running_sum]=i;
            }

        }
        
        return false;
        
    }
};
