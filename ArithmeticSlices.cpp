# define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        long long ans = 0;
        
        vector<map<ll,int>>dp(n); // <diffrence,sequence ending with this diffrence at this index.>
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++){
                
                long long differ = (long long)nums[i] - (long long) nums[j];
                // check if difference values are not going out of bound.
                if(differ<=INT_MIN || differ>=INT_MAX){
                    continue;
                }
                
                int seqUptoNow = 0;
                
                if(dp[j].find(differ) != dp[j].end()){
                    seqUptoNow = dp[j][differ];
                }
                dp[i][differ] += seqUptoNow + 1;
                ans += seqUptoNow;
              
            }
        }
        
        return (int)ans;
        
        
        
        
    }
};
