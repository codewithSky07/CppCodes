class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        int currentSum=0;
        int ans =0;
        mp[0]++;
        
        for(auto x:nums){
            currentSum+=x;
            int mod = (currentSum %k +k)%k;
            
            // check if mod already present
            if(mp.find(mod)!=mp.end()){
                ans+=mp[mod];
            }
            mp[mod]++;
        }
        return ans;


    }
};
