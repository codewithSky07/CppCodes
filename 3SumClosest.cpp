class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n<3) return 0;
        
        sort(nums.begin(),nums.end());
        
        int ans =0;
        int closest = INT_MAX;
        
        // traverse i =0 to n-3;
        for(int i=0;i<=n-3;i++){
            int j =i+1;
            int l = n-1;
            
            while(j<l){
                int tempsum = nums[i]+nums[j]+nums[l];
                
                if(abs(target-tempsum)<closest){
                    closest = abs(target-tempsum);
                    ans = tempsum;
                }
                else if(tempsum<target){
                    j++;
                }
                else{
                    l--;
                }
            }
        }
        return ans;
    }
};
