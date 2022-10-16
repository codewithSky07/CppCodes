class Solution {

    int dp[12][302];
    
    public:
    
    int maxValue(int i,int j, vector<int>&arr){
        int maxi = -1;
        
        for(int k=i;k<=j;k++){
            maxi = max(maxi,arr[k]);
        }
        
        return maxi;
    }
  
    int minDifficulty(vector<int>& arr, int day) {
        //
        int n = arr.size();
        
        //illegal
        if(n<day) return -1;
        
        
        // initialize.
        for(int i=0;i<=day;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = 1e6; 
            }
        }
        
        // base case. d=1
        for(int i=0;i<n;i++){ dp[1][i] = maxValue(i,n-1,arr);}
        
        // normal segemt
        
        for(int d= 2;d<=day;d++){
            for(int i=0;i<n;i++){
                // too manys days.. illegal
                if(n-i<d){
                    dp[d][i] = 1e6;
                    continue;
                }
                
                //segment with this loop.
                for(int j=i;j<n;j++){
                    dp[d][i] = min(dp[d][i],maxValue(i,j,arr)+dp[d-1][j+1]);
                }
            }
        }
        
        return dp[day][0];
        
        
    }
};
