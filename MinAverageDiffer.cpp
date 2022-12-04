class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        long long totalsum = 0;
        int n = nums.size();
        vector<long long>prefix(n);
        
        for(int i=0;i<n;i++){
            totalsum +=nums[i];
            prefix[i] = totalsum;
        }
        
        int minval = INT_MAX;
        int ansindex =0;
        
        for(int i=0;i<n;i++){
            int divpart = i+1;
            
            long long firstpart = prefix[i]/divpart;
            long long secondpart=0;
            
            if(n-divpart != 0){
             secondpart = (totalsum-prefix[i])/(n-divpart);}
            
            long long tempcal =  abs(firstpart-secondpart);
            
            if(tempcal < minval){
                minval = tempcal;
                ansindex = i;
            }
            
        }
        return ansindex;      
    }
};
